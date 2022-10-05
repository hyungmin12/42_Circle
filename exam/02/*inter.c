/*
[Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/

// str 변화해주는 프로그램 x
// str 겹치는거, 중복 

#include <unistd.h>

// 한번도 안나온숫자 . check[128]
//
//first[1] = 'a';   (int)'a' --> 97;
// check[ (int)first[1] ]
// check[97]  => 1로 수정.

// check[0] = 0;
// check[1] = 0;
// ////
// check[97] = ;'
// check[98] = 0;
//
// check[112] = 0;

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		char *first = argv[1];
		char *seconde = argv[2];

		int i = 0;
		int check[128];
		
		while (i < 128)
			check[i++] = 0;


		i = 0;
		while (seconde[i])			// p -> 112
		{
			if (check[ (int)seconde[i] ] == 0) // check[112] = 0
			{
				check[ (int)seconde[i] ] = 1; // check[112] = 1;
			}
			i++;
		}


		i = 0;
		while (first[i])  // p
		{
			if (check[ (int)first[i] ] == 1) // check[112] == 1
			{
				check[ (int)first[i] ] = 2; // check[112] = 2
				write(1, &first[i] , 1);  // write(1, "p", 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
