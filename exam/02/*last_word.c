
/*
 * Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/





#include <unistd.h>


// 띄어 쓰기나, 탭을 인식하면 1을 반환
int is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *str = argv[1];

		int i = ft_strlen(str) - 1;
		while (str[i]) // 뒤에서부터  " dwdqw dwd qw dwdwq  dwdwq "
		{
			if (str[i] && !is_space(str[i])) // !is_space ->문자
			{
				while (str[i] && !is_space(str[i]))
					i--;
				i++;	 // 중요	
				break ;	//	중요
			}
			else
				i--;
		}

		while (str[i] && !is_space(str[i]))
			write(1, &str[i++], 1);

	}
	write(1, "\n", 1);
	return (0);
}
