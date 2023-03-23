#ifndef PHONEBOOKAPP_HPP
# define PHONEBOOKAPP_HPP
# include <string>
# include "PhoneBook.hpp"

class PhoneBookApp {
private:
	PhoneBook pb ;
	std::string cmd ;
public:
	PhoneBookApp () ;
	int run() ;
} ;

#endif
