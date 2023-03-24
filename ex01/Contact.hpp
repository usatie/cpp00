#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
class Contact {
private:
	int			_i ;
	std::string _first_name ;
	std::string _last_name ;
	std::string _nickname ;
	std::string _phone_number ;
	std::string _darkest_secret ;
public:
	Contact () ;
	Contact (int i, std::string f, std::string l, std::string n, std::string p, std::string d) ;
	void	printSummary() ;
	void	printDetail() ;
	static void	printHeader() ;
} ;
#endif
