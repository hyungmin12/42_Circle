/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:23:03 by hyyoo             #+#    #+#             */
/*   Updated: 2022/09/21 16:50:05 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	len;

	if (!str)
		str = "(null)";
	i = 0;
	len = 0;
	while (str[i])
	{
		len += ft_putchar(str[i++]);
		if (len == -1)
			return (-1);
	}
	return (len);
}
