#include "PhoneBook.hpp"
#include "readutil.hpp"
#include <iostream>

PhoneBook::PhoneBook (): _size(0), _next_index(0) {}

int	PhoneBook::add() {
	std::string f, l, n, p, d ;
	if ( getline("First Name: ", f) == ERROR ) return ERROR ;
	if ( getline("Last Name: ", l) == ERROR ) return ERROR ;
	if ( getline("Nickname: ", n) == ERROR ) return ERROR ;
	if ( getline("Phone Number: ", p) == ERROR ) return ERROR ;
	if ( getline("Darkest Secret: ", d) == ERROR ) return ERROR ;
	_contacts[_next_index] = Contact(_next_index, f, l, n, p, d) ;
	_next_index++ ;
	_next_index %= PHONEBOOK_SIZE ;
	if ( _size < PHONEBOOK_SIZE )
		_size++ ;
	return SUCCESS ;
}

int	PhoneBook::search() {
	Contact::printHeader() ;
	for ( int i = 0 ; i < _size ; i++ ) {
		_contacts[i].printSummary() ;
	}

	int index ;
	if( getNumber("Enter the index of the entry to display: ", index) == ERROR )
		return ERROR ;
	else if ( index >= 0 && index < _size ) {
		_contacts[index].printDetail() ;
	}
	else
		std::cout << "index is out of range\n" ;
	return SUCCESS ;
}
