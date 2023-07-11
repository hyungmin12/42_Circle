/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:56:23 by hyyoo             #+#    #+#             */
/*   Updated: 2023/06/29 20:43:55 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_ch_str_cnt(char **p_str, int count)
{
	int	i;

	i = 0;
	while (p_str[i])
		i++;
	if (i != count)
		ft_error();
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	check_comma_count(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			count ++;
	}
	if (count != 2)
		ft_error();
}

static void	check_valid_color(char *str)
{
	int	i;

	if (!str || !*str || ft_strlen(str) > 4)
		ft_error();
	if (*str == '+' || *str == '-')
		str ++;
	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error();
	}
}

void	parse_rgb(char *str, int *color_store)
{
	char	**p_str;
	int		i;

	check_comma_count(str);
	p_str = ft_split(str, ',');
	ft_ch_str_cnt(p_str, 3);
	free(str);
	i = -1;
	while (++i < 3)
	{
		check_valid_color(p_str[i]);
		color_store[i] = ft_atoi(p_str[i]);
		free(p_str[i]);
		if (color_store[i] < 0 || color_store[i] > 255)
			ft_error();
	}
	free(p_str);
}
