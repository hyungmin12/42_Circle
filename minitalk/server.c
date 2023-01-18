/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:02:38 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/18 21:56:04 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*error(char *str)
{
	write(2, "Error : ", ft_strlen("Error : "));
	write(2, str, ft_strlen(str));
	write(2, "\n", ft_strlen("\n"));
	exit(1);
}

/*
* 에러없음 : getpid 범위지정 필요 없음.
*/

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
		pid = getpid();
		ft_putnbr(pid);
		while (1)
		{
			signal(SIGUSR1, print_msg);
			signal(SIGUSR2, print_msg);
			pause();
		}
	}
	else
		error("ac more than 1");
}
