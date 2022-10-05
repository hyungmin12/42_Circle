/*

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str "vous   voyez   c'est   facile   d'afficher   la   meme   chose" | cat -e
vous   voyez   c'est   facile   d'afficher   la   meme   chose$
$> ./expand_str " seulement          la c'est      plus dur " | cat -e
seulement   la   c'est   plus   dur$
$> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./expand_str "" | cat -e
$
$>
 
 */



#include <unistd.h>

int is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}


int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *str = argv[1];

		int i = 0;
		while (str[i])
		{
			if (str[i] && !is_space(str[i]))
			{
				while (str[i] && !is_space(str[i]))
				{
					write(1, &str[i++], 1);
				}
				if (str[i] && str[i + 1])// str[i] 안쓰면 어떻게되는지
				{
					write(1, " ", 1);
					write(1, " ", 1);
					write(1, " ", 1);
				}
			}
			else
				i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

