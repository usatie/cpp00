#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

#define SUCCESS 0
#define ERROR -1
#define COL_WIDTH 10

static int get_string(const std::string & prompt, std::string & s)
{
	std::cout << prompt ;
	while ( std::getline(std::cin, s) )
	{
		if ( s != "" )
			return 1 ;
		std::cout << prompt ;
	}
	return 0;
}

int	PhoneBook::add() {
	Contact & contact = contacts[size % PHONEBOOK_SIZE] ;
	if ( get_string("First Name: ", contact.first_name) == 0 ) return ERROR ;
	if ( get_string("Last Name: ", contact.last_name) == 0 ) return ERROR ;
	if ( get_string("Nickname: ", contact.nickname) == 0 ) return ERROR ;
	if ( get_string("Phone Number: ", contact.phone_number) == 0 ) return ERROR ;
	if ( get_string("Darkest Secret: ", contact.darkest_secret) == 0 ) return ERROR ;
	size++ ;
	return SUCCESS ;
}

static std::string trunc( std::string str ) {
	if ( str.size() > COL_WIDTH )
	{
		str.resize(COL_WIDTH) ;
		str[9] = '.' ;
	}
	return str ;
}

static int getIndex( int & index ) {
	std::string s ;
	std::size_t pos ;

	std::cout << "Enter the index of the entry to display: " ;
	if ( std::getline(std::cin, s) == 0 )
		return ERROR ;

	try {
		index = std::stoi(s, &pos) ;
		if ( index < 0 )
			std::cout << "index is out of range\n" ;
		return (index) ;
	}
	catch(std::invalid_argument const &ex)
	{
		std::cout << "std::invalid_argument::what(): " << ex.what() << "\n" ;
		return ERROR;
	}
	catch(std::out_of_range const &ex)
	{
		std::cout << "std::out_of_range::what(): " << ex.what() << "\n" ;
		return ERROR;
	}
}

int	PhoneBook::search() {
	std::cout
		<< std::setw(10) << "index" << "|"
		<< std::setw(10) << "first_name" << "|"
		<< std::setw(10) << "last_name" << "|"
		<< std::setw(10) << "nickname" << "\n" ;
	for ( int i = 0 ; i < size ; i++ ) {
		Contact & contact = contacts[i] ;
		std::cout
			<< std::setw(10) << i << "|"
			<< std::setw(10) << trunc(contact.first_name) << "|"
			<< std::setw(10) << trunc(contact.last_name) << "|"
			<< std::setw(10) << trunc(contact.nickname) << "\n" ;
	}

	int index ;
	if( getIndex(index) == ERROR )
		return ERROR ;
	else if ( index < size ) {
		Contact & contact = contacts[index] ;
		std::cout
			<< std::setw(20) << "Index: " << index << "\n"
			<< std::setw(20) << "First Name: " << contact.first_name << "\n"
			<< std::setw(20) << "Last Name: " << contact.last_name << "\n"
			<< std::setw(20) << "Nickname: " << contact.nickname << "\n"
			<< std::setw(20) << "Phone Number: " << contact.phone_number << "\n"
			<< std::setw(20) << "Darkest Secret: " << contact.darkest_secret << "\n" ;
	}
	else
		std::cout << "index is out of range\n" ;
	return SUCCESS ;
}
