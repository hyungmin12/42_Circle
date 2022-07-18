/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:26:56 by hyyoo             #+#    #+#             */
/*   Updated: 2022/07/15 17:38:21 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	rev(int nb, int fd)
{
	char	ch;

	if (nb == 0)
		return ;
	else
	{
		rev(nb / 10, 1);
		ch = '0' + (nb % 10);
		write(fd, &ch, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
		}
		rev(n / 10, fd);
		c = n % 10 + '0';
		write(fd, &c, 1);
	}
}
