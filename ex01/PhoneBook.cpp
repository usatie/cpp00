#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

#define COL_WIDTH 10
#define TITLE_WIDTH 20

static int 			getline(const std::string & prompt, std::string & s) ;
static int 			getIndex( const std::string & prompt, int & index ) ;
static std::string	trunc( std::string str ) ;

PhoneBook::PhoneBook (): size(0), index(0) {}

int	PhoneBook::add() {
	Contact & contact = contacts[index] ;
	if ( getline("First Name: ", contact.first_name) == ERROR ) return ERROR ;
	if ( getline("Last Name: ", contact.last_name) == ERROR ) return ERROR ;
	if ( getline("Nickname: ", contact.nickname) == ERROR ) return ERROR ;
	if ( getline("Phone Number: ", contact.phone_number) == ERROR ) return ERROR ;
	if ( getline("Darkest Secret: ", contact.darkest_secret) == ERROR ) return ERROR ;
	index++ ;
	index %= PHONEBOOK_SIZE ;
	if ( size < PHONEBOOK_SIZE )
		size++ ;
	return SUCCESS ;
}

int	PhoneBook::search() {
	std::cout
		<< std::setw(COL_WIDTH) << "index" << "|"
		<< std::setw(COL_WIDTH) << "first_name" << "|"
		<< std::setw(COL_WIDTH) << "last_name" << "|"
		<< std::setw(COL_WIDTH) << "nickname" << "\n" ;
	for ( int i = 0 ; i < size ; i++ ) {
		Contact & contact = contacts[i] ;
		std::cout
			<< std::setw(COL_WIDTH) << i << "|"
			<< std::setw(COL_WIDTH) << trunc(contact.first_name) << "|"
			<< std::setw(COL_WIDTH) << trunc(contact.last_name) << "|"
			<< std::setw(COL_WIDTH) << trunc(contact.nickname) << "\n" ;
	}

	int index ;
	if( getIndex("Enter the index of the entry to display: ", index) == ERROR )
		return ERROR ;
	else if ( index >= 0 && index < size ) {
		Contact & contact = contacts[index] ;
		std::cout
			<< std::setw(TITLE_WIDTH) << "Index: " << index << "\n"
			<< std::setw(TITLE_WIDTH) << "First Name: " << contact.first_name << "\n"
			<< std::setw(TITLE_WIDTH) << "Last Name: " << contact.last_name << "\n"
			<< std::setw(TITLE_WIDTH) << "Nickname: " << contact.nickname << "\n"
			<< std::setw(TITLE_WIDTH) << "Phone Number: " << contact.phone_number << "\n"
			<< std::setw(TITLE_WIDTH) << "Darkest Secret: " << contact.darkest_secret << "\n" ;
	}
	else
		std::cout << "index is out of range\n" ;
	return SUCCESS ;
}

static int getline(const std::string & prompt, std::string & s)
{
	std::cout << prompt ;
	while ( std::getline(std::cin, s) )
	{
		if ( s != "" )
			return SUCCESS ;
		std::cout << prompt ;
	}
	return ERROR;
}

static int getIndex( const std::string & prompt, int & index ) {
	std::string s ;
	std::size_t pos ;

	if ( getline(prompt, s) == ERROR )
		return ERROR ;

	try {
		index = std::stoi(s, &pos) ;
		if ( index < 0 )
			std::cerr << "index is out of range\n" ;
	}
	catch(std::invalid_argument const &ex)
	{
		index = -1 ;
		std::cerr << "std::invalid_argument::what(): " << ex.what() << "\n" ;
	}
	catch(std::out_of_range const &ex)
	{
		index = -1 ;
		std::cerr << "std::out_of_range::what(): " << ex.what() << "\n" ;
	}
	return SUCCESS ;
}

static std::string trunc( std::string str ) {
	if ( str.size() > COL_WIDTH )
	{
		str.resize(COL_WIDTH) ;
		str[COL_WIDTH - 1] = '.' ;
	}
	return str ;
}
