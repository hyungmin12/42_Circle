/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 23:57:53 by hyyoo             #+#    #+#             */
/*   Updated: 2022/09/16 22:04:24 by hyyoo            ###   ########.fr       */
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
		write(1, &hex[n], 1);
}

int	ft_putx(unsigned long long p)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	if (p == 0)
		i += ft_putchar('0');
	else
	{
		ft_putnumx(p);
		i += ft_len(p);
	}
	return (i);
}
