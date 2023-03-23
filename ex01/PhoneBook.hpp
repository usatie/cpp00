#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# define PHONEBOOK_SIZE 8
# define SUCCESS 0
# define ERROR -1

class PhoneBook {
private:
	Contact contacts[PHONEBOOK_SIZE] ;
	int		size ;
	int		index ;
public:
	PhoneBook ();
	int	add();
	int	search();
} ;
#endif
