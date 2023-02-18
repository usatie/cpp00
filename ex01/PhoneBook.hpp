#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# define PHONEBOOK_SIZE 8

class PhoneBook {
	Contact contacts[PHONEBOOK_SIZE] ;
	std::size_t		size ;
public:
	PhoneBook (): size(0) {};
	int	add();
	int	search();
} ;
#endif
