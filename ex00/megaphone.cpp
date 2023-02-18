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
	}
	else
	{
		for ( int i = 1 ; i < argc ; ++i )
			megahpone(argv[i]) ;
	}
	std::cout << "\n" ;
}
