/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:15:12 by hyyoo             #+#    #+#             */
/*   Updated: 2022/12/29 13:36:08 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int						sign;
	int						i;
	unsigned long int		ret;

	i = 0;
	sign = 1;
	ret = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = sign * -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + str[i] - '0';
		i++;
		if (ret > 2147483647 && sign == 1)
			return (-1);
		if (ret > 2147483648 && sign == -1)
			return (0);
	}
	return (ret * sign);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	send_bit(char origin_char, int pid)
{
	int		bit_push;
	char	shifted_char;

	bit_push = 8;
	while (bit_push--)
	{
		shifted_char = origin_char >> bit_push;
		if ((shifted_char & 1) == 1)
			kill(pid, SIGUSR1);
		else if ((shifted_char & 1) == 0)
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

void	send_msg(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
		send_bit(str[i++], pid);
}

int	main(int ac, char **av)
{
	if (ac == 3 && is_number(av[1]))
	{
		send_msg(av[2], ft_atoi(av[1]));
	}
	else
		ft_printf("no");
}
