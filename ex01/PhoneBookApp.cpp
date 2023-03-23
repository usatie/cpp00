#include "PhoneBookApp.hpp"
#include "PhoneBook.hpp"
#include <iostream>

static int getline(const std::string & prompt, std::string & s) ;

PhoneBookApp::PhoneBookApp() {}

int	PhoneBookApp::run()
{
	while ( getline("Enter a Command(ADD/SEARCH/EXIT): ", cmd) == SUCCESS )
	{
		if ( cmd == "ADD" )
		{
			if ( pb.add() == ERROR )
				return EXIT_FAILURE ;
		}
		else if ( cmd == "SEARCH" )
		{
			if ( pb.search() == ERROR )
				return EXIT_FAILURE ;
		}
		else if ( cmd == "EXIT" )
			return EXIT_SUCCESS ;
		else if ( cmd == "" )
			continue ;
		else
			std::cout << "No such command: " << cmd << "\n" ;
	}
	return EXIT_FAILURE ;
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
