#include <unistd.h>


int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		int first_word = 0;

		char *str = argv[1];

		while (str[i] && (str[i] == ' ' || str[i] == '\t'))	
			i++;
		// "abc def"
		// "   abc def"
		// 
		// i는 첫번째 인덱스를 가리킴 (만약에 있다면)
		
		first_word = i;

		while (str[i] && (str[i] != ' ' && str[i] != '\t'))
			i++;

		// "	Que la      lumiere soit et la lumiere fut	"
		//		|  | (i index)
		//      | (first_word)
		while (str[i])
		{
			if (str[i] != ' ' && str[i] != '\t')
			{
				while (str[i] && str[i] != ' ' && str[i] != '\t')
				{	
					write(1, &str[i], 1);
					i++;
				}
				write(1, " ", 1);
			}
			else
				i++;
		}

		// print last wor
		while (str[first_word] && str[first_word] != ' ' && str[first_word] != '\t')
			write(1, &str[first_word++], 1);

	}
	write(1,"\n", 1);
	return (0);
}
