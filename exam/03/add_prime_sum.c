/*
 
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>

*/






















#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

int		ft_atoi(char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}

int		ft_is_prime(int nb)
{
	int i;

	i = 2;
	while (i < nb) // 7  ( 2, 3,4,5 6)으로 안나눠짐
	{
		if (nb % i == 0) // 7이라면,  1 2 3 4 5 6까지 안나눠지면 소수!
			return (0);
		i++;
	}
	return (1);

}

int		ft_add_prime_sum(int nb)
{
	int i;
	int prime_sum;

	i = 2; // 중요 2,3,5,7,9...
	prime_sum = 0;
	
	if (nb <= 0)  // 중요, - 또는 0은 없음
		return (0);
	
	while (i <= nb)	// =nb 까지!   5이면, 2 + 3 + 5 이다.
	{
		if (ft_is_prime(i))  // 소수라면
			prime_sum += i;  // 그 수는 계속 더한다.
		i++;
	}
	return (prime_sum);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_putnbr(ft_add_prime_sum(ft_atoi(argv[1])));
	else
		write(1, "0", 1); // 아무인자도없거나 마이너스면 경우에는 0을 출력해야하므로.
	write(1, "\n", 1);
	return (0);
}
