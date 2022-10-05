/*
Assignment name  : hidenp
Expected files   : hidenp.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.

If the number of parameters is not 2, the program displays a newline.

Examples :

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>
 */

#include <unistd.h>

int		main(int ac, char **av)
{
	int i;
	int i2;
	int count;

	i = 0;
	i2 = 0;
	count = 0;
	if (ac == 3)
	{
		while (av[1][i] != '\0')
		{
			while (av[2][i2] != '\0')
			{
				if (av[1][i] == av[2][i2])
				{
					count++;
					break ;
				}
				i2++;
			}
			i++;
		}
		if (av[1][count] == '\0')
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}




#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		char *s1 = argv[1];
		char *s2 = argv[2];

		int index_s1 = 0;
		int index_s2 = 0;
		int len_s1 = 0;

		// 우선 s1의 길이를 확인
		while (s1[len_s1])
			len_s1++;

		// s2를 탐색하면서, 확인
		while (s2[index_s2] && index_s1 < len_s1)
		{
			if (s2[index_s2] == s1[index_s1])
				index_s1++;
			index_s2++;
		}

		if (index_s1 == len_s1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}
