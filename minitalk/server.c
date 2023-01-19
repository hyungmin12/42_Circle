/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:02:38 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/19 18:58:13 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_error_msg(char *str)
{
	write(2, "Error : ", ft_strlen("Error : "));
	write(2, str, ft_strlen(str));
	write(2, "\n", ft_strlen("\n"));
	exit(1);
}

void	print_msg(int sig)
{
	static char	save_char;
	static int	save_cnt;

	save_cnt++;
	save_char = save_char << 1;
	if (sig == SIGUSR1)
		save_char += 1;
	if (save_cnt == 8)
	{
		ft_putchar(save_char);
		save_cnt = 0;
		save_char = 0;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	(void) av;
	if (ac == 1)
	{
		write(1, "Server PID : ", 13);
		pid = getpid();
		ft_putnbr(pid);
		write(1, "\nsend msg is : ", ft_strlen("\nsend_msg is : "));
		while (1)
		{
			if (signal(SIGUSR1, print_msg) == SIG_ERR)
				ft_error_msg("can't handle SIGINT!\n");
			if (signal(SIGUSR2, print_msg) == SIG_ERR)
				ft_error_msg("can't handle SIGINT!\n");
			pause();
		}
	}
	else
		ft_error_msg("ac errer");
}
