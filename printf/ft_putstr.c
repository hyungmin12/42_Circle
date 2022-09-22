/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:23:03 by hyyoo             #+#    #+#             */
/*   Updated: 2022/09/22 17:46:49 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	len;
	int	cnt;

	if (!str)
		str = "(null)";
	cnt = 0;
	i = 0;
	len = 0;
	while (str[i])
	{
		len = ft_putchar(str[i++]);
		if (len == -1)
			return (-1);
		cnt += len;
	}
	return (cnt);
}
