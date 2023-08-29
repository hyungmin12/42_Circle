/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:15:12 by hyyoo             #+#    #+#             */
/*   Updated: 2023/08/29 19:05:18 by yuhyeongmin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(char origin_char, int pid)
{
	int		bit_push;
	char	shifted_char;
	int		kill_cnt;

	kill_cnt = 0;
	bit_push = 8;
	while (bit_push--)
	{
		shifted_char = origin_char >> bit_push; 
		// 비트 이동 결과를 저장하는 변수,  매개변수인 원래 문자에서 8개 7, 6개 이렇게 하나씩 비트를 밀어서
		// shifted_char에 저장함
		if ((shifted_char & 1) == 1) //and연산을 통해 만약 밀어낸 비트가 1이라면
		{
			//sigusr1을 보냄 sigusr1은 그냥 사용자 정의 signal로 받는 쪽에서 
			// 만약 sigusr1이라면 1로 정의 하겠다 이런식으로 씀
			// server.c의 39번줄에서 받음
			if (kill(pid, SIGUSR1) == 1) 
			{
				write(1, "kill error", ft_strlen("kill error"));
				exit(1);
			}
		}
		else if ((shifted_char & 1) == 0) //0이라면
		{
			if (kill(pid, SIGUSR2) == 1) //sigusr2보냄
			{
				write(1, "kill error", ft_strlen("kill error"));
				exit(1);
			}
		}
		kill_cnt++;
		usleep(100); //비트 보내고 서버에서 받아야할 시간도 있으니 잠시 멈춰줌 안 멈추면 이상하게 수신함.
	}
	ft_putnbr(kill_cnt);
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

//위치 8:  0 1 0 0 0 0 0 1   // 'A'를 8비트로 표현한 이진수 (원래 문자)
// 위치 7:  0 0 1 0 0 0 0 0   // 오른쪽으로 1비트 이동한 결과
// 위치 6:  0 0 0 1 0 0 0 0   // 오른쪽으로 2비트 이동한 결과
// 위치 5:  0 0 0 0 1 0 0 0   // 오른쪽으로 3비트 이동한 결과
// 위치 4:  0 0 0 0 0 1 0 0   // 오른쪽으로 4비트 이동한 결과
// 위치 3:  0 0 0 0 0 0 1 0   // 오른쪽으로 5비트 이동한 결과
// 위치 2:  0 0 0 0 0 0 0 1   // 오른쪽으로 6비트 이동한 결과
// 위치 1:  0 0 0 0 0 0 0 0   // 오른쪽으로 7비트 이동한 결과
//