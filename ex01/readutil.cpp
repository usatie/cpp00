#include "readutil.hpp"
#include <iostream>

int getline(const std::string & prompt, std::string & s)
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

int getNumber( const std::string & prompt, int & index ) {
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
