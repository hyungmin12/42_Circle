/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:49:51 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/18 21:49:52 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr_fd(int n)
{
	char		str[11];
	long long	nb;
	int			index;

	index = 0;
	nb = (long long)n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	else if (nb == 0)
		write(1, "0", 1);
	while (nb > 0)
	{
		str[index++] = nb % 10 + '0';
		nb /= 10;
	}
	while (--index >= 0)
		write(1, &str[index], 1);
	write(1, "\n", 1);
}
