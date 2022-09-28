/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:39:54 by hyyoo             #+#    #+#             */
/*   Updated: 2022/05/29 23:59:22 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	ret;
	int	nb;

	ret = 0;
	nb = 1;
	while (*str && ((*str == '\f') || (*str == '\r')
			|| (*str == ' ') || (*str == '\t')
			|| (*str == '\n') || (*str == '\v')))
		str++;
	while (*str && ((*str == '+') || (*str == '-')))
	{
		if (*str == '-')
			nb *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{	
			ret = ret * 10;
			ret += *str - '0';
			str++;
	}
	return (ret * nb);
}
