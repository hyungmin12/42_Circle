/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:24:16 by hyyoo             #+#    #+#             */
/*   Updated: 2022/08/27 17:36:52 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_puthex(unsigned long num, char c)
{
	int	i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	
	if (c == 'X')
		hex = "0123456789ABCDEF";
	if (num > 15)
	{
		i += ft_puthex(num / 16, c);
		i += ft_puthex(num % 16, c);
	}
	else
		i += write (1, &hex[num], 1);
	return (i);
}
/*
int	ft_puthex(unsigned long n, char x)
{
	int		counter;
	char	*str;

	str = "0123456789abcdef";
	counter = 0;
	if (x == 'X')
		str = "0123456789ABCDEF";
	if (n > 15)
	{
		counter += ft_puthex(n / 16, x);
		counter += ft_puthex(n % 16, x);
	}
	else
		counter += ft_putchar(str[n]);
	return (counter);
}*/
