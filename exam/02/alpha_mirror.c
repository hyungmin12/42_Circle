
/*
 
Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>
 
 */




//  abcdefghijklm   nopqrstuvwxyz

/*
char *str = "12";

char *str_(char *str)
{
	char tmp;
	char a = str[0]; // 1
	char b = str[1]; // 2
	tmp = a;
	a = b;
	b = tmp;
}
*/

//abcdef


//zyxwvu

 //'y' = 155('a' + 'z') - 'b';



//  abcdefghijklm   nopqrstuvwxyz

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
'a' -> 'z'
 97 -> 122
 97 + 122 = 219

 'b' -> 'y'
 98 -> 121
 98 + 121 == 219

 'y' = 'b'
 121 = 219 - 98
*/

int main(int argc, char **argv)
{
	int s_alpha = 'a' + 'z';
	int b_alpha = 'A' + 'Z';

	if (argc == 2)
	{
		int i = 0;
		char *str = argv[1];

		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = s_alpha - str[i];
			else if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = b_alpha - str[i];
			ft_putchar(str[i]);
			i++;
		}
	}

	ft_putchar('\n');
	return (0);
}






































