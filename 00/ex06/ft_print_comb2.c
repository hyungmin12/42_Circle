/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:32:18 by hyyoo             #+#    #+#             */
/*   Updated: 2022/05/29 03:05:10 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar2(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_putchar2((a / 10) + '0');
			ft_putchar2((a % 10) + '0');
			ft_putchar2(' ');
			ft_putchar2((b / 10) + '0');
			ft_putchar2((b % 10) + '0');
			if (a != 98)
			{
				ft_putchar2(',');
				ft_putchar2(' ');
			}
			b++;
		}
		a++;
	}
}
