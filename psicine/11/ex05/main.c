#include <unistd.h>
#include "ft.h"
 
int	main(int ac, char **av)
{
	int	result;
 
	if (ac == 4)
	{
		if (check_error(av[2]) == -1)
		{
			write(1, "0\n", 2);
			return (0);
		}
		result = ft_cal(ft_atoi(av[1]), ft_atoi(av[3]), av[2][0]);
		if (ft_atoi(av[3]) == 0 && av[2][0] == '/')
		{
			write(1, "Stop : division by zero\n", 24);
			return (0);
		}
		if (av[2][0] == '%' && ft_atoi(av[3]) == 0)
		{
			write(1, "Stop : modulo by zero\n", 22);
			return (0);
		}
		ft_putnbr(result);
		write(1, "\n", 1);
	}
	return (0);
}
 
int	check_error(char *str)
{
	if (str[1] != 0)
		return (-1);
	if (str[0] == '+' || str[0] == '-' || str[0] == '*'
		|| str[0] == '%' || str[0] == '/')
		return (1);
	return (-1);
}
 
int	ft_cal(int num1, int num2, char op)
{
	if (op == '+')
		return (ft_plus(num1, num2));
	else if (op == '-')
		return (ft_minor(num1, num2));
	else if (op == '*')
		return (ft_multi(num1, num2));
	else if (op == '/' && num2 != 0)
		return (ft_div(num1, num2));
	else
		return (ft_mod(num1, num2));
}
