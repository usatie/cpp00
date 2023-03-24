#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# define PHONEBOOK_SIZE 8
# define SUCCESS 0
# define ERROR -1

class PhoneBook {
private:
	Contact _contacts[PHONEBOOK_SIZE] ;
	int		_size ;
	int		_next_index ;
public:
	PhoneBook ();
	int	add();
	int	search();
} ;
#endif
