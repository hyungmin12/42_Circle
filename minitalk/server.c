/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:02:38 by hyyoo             #+#    #+#             */
/*   Updated: 2023/08/29 19:05:19 by yuhyeongmin      ###   ########.fr       */
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

#include<stdio.h>
void	print_msg(int sig)
{
	static char	save_char;
	static int	save_cnt;

	save_cnt++;
	save_char = save_char << 1;
	// printf("%c\n", save_char);
	// 초기: save_char = 00000000
	// 첫 번째 SIGUSR1: save_char = 00000001
	// 두 번째 SIGUSR1: save_char = 00000011
	// 그러나 이러한 비트 시퀀스는 아직 문자로 완성되지 않았기 때문에 save_cnt는 2입니다. 
	// 만약 이제 SIGUSR1이 6번 더 수신된다면, save_cnt가 8이 되어 문자를 완성하게 되고, 
	// ft_putchar를 사용하여 "3"을 출력한 다음 save_cnt와 save_char를 초기화합니다.
	
	if (sig == SIGUSR1) // sigusr1은 1로 정의해서 쓰는거
		save_char += 1;  //자기가 그냥 sigusr1이 오면 save_char+=1을 하겠다는 거임.
		
		//예를 들어 save_char가 0000 0000 이였다면, 위에서 << 1 해주고 그 자리에 1을 넣는거임
		// 그럼 save_char == 0000 0001 이 될거고, 그런식으로 계속 하면서 save_cnt를 8까지 추가시키면
		// 8비트가 모였을때 save_char는 client에서 보낸 문자를 수신한게 됨
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
		if (signal(SIGUSR1, print_msg) == SIG_ERR)
			ft_error_msg("can't handle SIGINT!\n");
		if (signal(SIGUSR2, print_msg) == SIG_ERR)
			ft_error_msg("can't handle SIGINT!\n");
		while (1)
		{
			pause();
		}
	}
	else
		ft_error_msg("ac errer");
}

// SIGUSR1과 SIGUSR2 신호를 처리하는 print_msg 함수를 시그널 핸들러로 등록합니다.
// 그 후 무한 루프를 돌며 pause 함수를 통해 프로세스를 일시정지시키고, 신호가 도착하면 시그널 핸들러 함수가 호출됩니다.