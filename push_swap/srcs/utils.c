/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:24:21 by hyyoo             #+#    #+#             */
/*   Updated: 2023/02/09 17:38:20 by yuhyeongmin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_msg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v' || c == '\f')
		return (1);
	return (0);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	check_is_digit(const char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			ft_error_msg();
		i++;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		write(1, &str[i++], 1);
}
