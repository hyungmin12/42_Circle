/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:15:12 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/19 18:57:47 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(char origin_char, int pid)
{
	int		bit_push;
	char	shifted_char;

	bit_push = 8;
	while (bit_push--)
	{
		shifted_char = origin_char >> bit_push;
		if ((shifted_char & 1) == 1)
		{
			if (kill(pid, SIGUSR1) == 1)
			{
				write(1, "kill error", ft_strlen("kill error"));
				exit(1);
			}
		}
		else if ((shifted_char & 1) == 0)
		{
			if (kill(pid, SIGUSR2) == 1)
			{
				write(1, "kill error", ft_strlen("kill error"));
				exit(1);
			}
		}
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
		write(1, "ac error\n", 9);
}
