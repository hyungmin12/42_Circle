/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:26:07 by hyyoo             #+#    #+#             */
/*   Updated: 2022/10/17 14:38:06 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_head.h"

int	main(int ac, char **av)
{
	long	result;

	if (ac == 4)
	{
		if (no_do_this(av[2]) == -1)
		{
			write(1, "0\n", 2);
			return (0);
		}
		result = calcul(ft_atoi(av[1]), ft_atoi(av[3]), av[2][0]);
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

int	no_do_this(char *str)
{
	if (str[1] != 0)
		return (-1);
	if (str[0] == '+' || str[0] == '-' || str[0] == '*'
		|| str[0] == '%' || str[0] == '/')
		return (1);
	return (-1);
}

int	calcul(long ch1, long ch2, char op)
{
	if (op == '+')
		return (add(ch1, ch2));
	else if (op == '-')
		return (moin(ch1, ch2));
	else if (op == '*')
		return (x_this(ch1, ch2));
	else if (op == '/' && ch2 != 0)
		return (div(ch1, ch2));
	else
		return (mod(ch1, ch2));
}

int	this_size(long nb)
{
	int	i;

	i = 0;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
