#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

static std::string	get_string(const std::string & prompt)
{
	std::string s;

	std::cout << prompt ;
	std::cin >> s ;
	return s;
}

int	main()
{
	PhoneBook pb;
	std::string cmd ;

	while ( ( cmd = get_string("Enter a Command(ADD/SEARCH/EXIT): ") ) != ""  )
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n') ;
		if ( cmd == "ADD" )
		{
			if ( pb.add() < 0 )
				return EXIT_FAILURE ;
		}
		else if ( cmd == "SEARCH" )
		{
			if ( pb.search() < 0 )
				return EXIT_FAILURE ;
		}
		else if ( cmd == "EXIT" )
			return EXIT_SUCCESS ;
	}
}
