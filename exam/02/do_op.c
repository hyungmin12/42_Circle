
/*
Assignment name  : do_op
Expected files   : *.c, *.h
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$
*/










#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
// 0 같다. - + 다르다

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		int first_num = atoi(argv[1]);
		int seconde_num = atoi(argv[3]);

		char *operator = argv[2];

		if (ft_strcmp(operator, "+") == 0)
			printf("%d\n", first_num + seconde_num);
		else if (ft_strcmp(operator, "-") == 0)
			printf("%d\n", first_num - seconde_num);
		else if (ft_strcmp(operator, "*") == 0)
			printf("%d\n", first_num * seconde_num);
		else if (ft_strcmp(operator, "/") == 0)
			printf("%d\n", first_num / seconde_num);
		else if (ft_strcmp(operator, "%") == 0)
			printf("%d\n", first_num % seconde_num);

	}
	else
		write(1, "\n", 1);	// else 후 개행
	return (0);
}





/*
 int		main(int ac, char **av)
{
	int a;
	int b;
	int result;
	char op;

	result = 0;
	if (ac == 4)
	{
		a = atoi(av[1]);
		op = av[2][0];
		b = atoi(av[3]);
		if (op == '+')
			result = a + b;
		else if (op == '-')
			result = a - b;
		else if (op == '*')
			result = a * b;
		else if (op == '/')
			result = a / b;
		else if (op == '%')
			result = a % b;
		printf("%d\n", result);
	}
	else
		write(1, "\n", 1);
	return (0);
}
 */










