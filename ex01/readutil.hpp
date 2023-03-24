#ifndef READUTIL_HPP
# define READUTIL_HPP
# define SUCCESS 0
# define ERROR -1
# include <string>

int	getline(const std::string & prompt, std::string & s) ;
int	getNumber( const std::string & prompt, int & index ) ;

#endif
