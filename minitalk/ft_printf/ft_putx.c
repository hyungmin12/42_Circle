/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 23:57:53 by hyyoo             #+#    #+#             */
/*   Updated: 2022/09/22 17:49:12 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar2(char c)
{
	write(1, &c, 1);
}

int	ft_len(unsigned long long n)
{
	int	i;

	i = 0;
	while (n)
	{
		i++;
		n /= 16;
	}
	return (i);
}

void	ft_putnumx(unsigned long long n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n > 15)
	{
		ft_putnumx(n / 16);
		ft_putnumx(n % 16);
	}
	else
		ft_putchar(hex[n]);
}

int	ft_putx(unsigned long long p)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	if (i == -1)
		return (-1);
	if (p == 0)
	{
		i += ft_putchar('0');
		if (i == -1)
			return (-1);
	}
	else
	{
		ft_putnumx(p);
		i += ft_len(p);
		if (i == -1)
			return (-1);
	}
	return (i);
}
