/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/


#include <unistd.h>


int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int check[128];

		int i = 0;
		while (i < 128)
		{
			check[i] = 0;
			i++;
		}

		char *first = argv[1];
		char *seconde = argv[2];

		int j = 0; // i로 써도됨 초기화하면!
		while (first[j])
		{
			if (check[ (int)first[j] ] == 0)
			{
				check[ (int)first[j] ] = 1;
				write(1, &first[j], 1);
			}
			j++;
		}

		int k = 0;
		while (seconde[k])
		{
			if (check[ (int)seconde[k] ] == 0)
			{
				check[ (int)seconde[k] ] = 1;
				write(1, &seconde[k], 1);
			}
			k++;
		}

	}
	write(1, "\n", 1);
	return (0);
}
