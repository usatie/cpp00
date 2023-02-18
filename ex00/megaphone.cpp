#include <iostream> // std::cout
#include <string>

#define MSG_DFL "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

char	toupper(char c)
{
	if ( 'a' <= c && c <= 'z' )
		return c + 'A' - 'a' ;
	return c ;
}

void	megahpone(const char *s)
{
	for ( char c = *s ; c ; c = *(++s) )
	{
		std::cout << toupper(c) ;
	}
}

int	main(int argc, char *argv[])
{
	if ( argc < 2 )
	{
		megahpone(MSG_DFL) ;
		std::cout << "\n" ;
		return 0 ;
	}
	for ( int i = 1 ; i < argc ; ++i )
	{
		if ( i > 1 ) std::cout << " " ;
		megahpone(argv[i]) ;
	}
	std::cout << "\n" ;
}
