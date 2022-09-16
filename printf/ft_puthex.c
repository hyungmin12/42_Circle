/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:24:16 by hyyoo             #+#    #+#             */
/*   Updated: 2022/09/16 19:56:24 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long num, char c)
{
	int		i;
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
