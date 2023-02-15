/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:41:09 by hyyoo             #+#    #+#             */
/*   Updated: 2023/02/15 22:09:40 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	ft_atoi(const char *str)
{
	int						sign;
	int						i;
	long long				ret;

	i = 0;
	sign = 1;
	ret = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = sign * -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	if (ret * sign > 2147483647 || ret * sign < -2147483648)
		ft_error_msg();
	return (ret * sign);
}

void	check_is_int(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] >= '0' && av[i][j] <= '9')
				|| av[i][j] == ' ' || av[i][j] == '-')
				j++;
			else
			{
				ft_error_msg();
			}
		}
		i++;
	}
}

void	ft_four(char **av, t_info *info)
{
	info->one = ft_atoi(av[1]);
	info->two = ft_atoi(av[2]);
	info->thr = ft_atoi(av[3]);
	info->four = ft_atoi(av[4]);
}

void	ft_five(char **av, t_info *info)
{
	info->one = ft_atoi(av[1]);
	info->two = ft_atoi(av[2]);
	info->thr = ft_atoi(av[3]);
	info->four = ft_atoi(av[4]);
	info->five = ft_atoi(av[5]);
}

void    parcing(int ac, char **av, t_info *info)
{
	check_is_int(av);
	if (ac == 5)
		ft_four(av, info);
	else
		ft_five(av, info);
}
