/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:41:30 by hyyoo             #+#    #+#             */
/*   Updated: 2022/05/21 21:55:51 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar1(char c)
{
	write(1, &c, 1);
}

void	ft_put(char a, char b, char c)
{
	ft_putchar1 (a + '0');
	ft_putchar1 (b + '0');
	ft_putchar1 (c + '0');
	if (a == 7 && b == 8 && c == 9)
	{
	}
	else
	{
		ft_putchar1(',');
		ft_putchar1(' ');
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = 0;
	while (a <= 7)
	{
		b = a + 1;
		while (b <= 8)
		{
			c = b + 1;
			while (c <= 9)
			{
				ft_put(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
