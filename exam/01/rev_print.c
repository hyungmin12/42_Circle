
#include <unistd.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//1. 무한루프  --> while


int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *str = argv[1];
	
		int i = ft_strlen(str) - 1;
		// "abcde"
		//  e  ==> 4 == len - 1 
		//  d c b 
		//  a ==> 0
		//
		while (i >= 0)
		{
			write(1, &str[i], 1);
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
