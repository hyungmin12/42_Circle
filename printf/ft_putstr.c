/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:23:03 by hyyoo             #+#    #+#             */
/*   Updated: 2022/08/25 15:25:57 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_putstr(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (len);
}
