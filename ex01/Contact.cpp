#include "Contact.hpp"
#include <iostream>
#include <iomanip>

#define COL_WIDTH 10
#define TITLE_WIDTH 20

Contact::Contact (int i, std::string f, std::string l, std::string n, std::string p, std::string d):
	_i(i),
	_first_name(f),
	_last_name(l),
	_nickname(n),
	_phone_number(p),
	_darkest_secret(d) {} ;

Contact::Contact (): _i(0) {}

static std::string trunc( std::string str ) {
	if ( str.size() > COL_WIDTH )
	{
		str.resize(COL_WIDTH) ;
		str[COL_WIDTH - 1] = '.' ;
	}
	return str ;
}

void	Contact::printHeader(void)
{
	std::cout
		<< std::setw(COL_WIDTH) << "index" << "|"
		<< std::setw(COL_WIDTH) << "first_name" << "|"
		<< std::setw(COL_WIDTH) << "last_name" << "|"
		<< std::setw(COL_WIDTH) << "nickname" << std::endl ;
}

void	Contact::printSummary(void)
{
	std::cout
		<< std::setw(COL_WIDTH) << _i << "|"
		<< std::setw(COL_WIDTH) << trunc(_first_name) << "|"
		<< std::setw(COL_WIDTH) << trunc(_last_name) << "|"
		<< std::setw(COL_WIDTH) << trunc(_nickname) << "\n" ;
}

void	Contact::printDetail(void)
{
	std::cout
		<< std::setw(TITLE_WIDTH) << "Index: " << _i << std::endl
		<< std::setw(TITLE_WIDTH) << "First Name: " << _first_name << std::endl
		<< std::setw(TITLE_WIDTH) << "Last Name: " << _last_name << std::endl
		<< std::setw(TITLE_WIDTH) << "Nickname: " << _nickname << std::endl
		<< std::setw(TITLE_WIDTH) << "Phone Number: " << _phone_number << std::endl
		<< std::setw(TITLE_WIDTH) << "Darkest Secret: " << _darkest_secret << std::endl ;
}
