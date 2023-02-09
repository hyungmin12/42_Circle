/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:06:50 by hyyoo             #+#    #+#             */
/*   Updated: 2023/02/09 16:05:23 by yuhyeongmin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_split_size(char **split_str)
{
	int	i;

	i = 0;
	while (split_str[i])
		i++;
	return (i);
}

int	ft_str_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	get_array_size(char **av)
{
	char	**split_str;
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (av[i])
	{
		if (ft_str_space(av[i]))
		{
			split_str = ft_split(av[i], ' ');
			size += get_split_size(split_str);
			free_str(split_str);
		}
		else
			size++;
		i++;
	}
	return (size - 1);
}

int	*get_num_array(char **av, int size)
{
	char	**split_str;
	int		*nums;
	int		ac_size;
	int		j;
	int		i;

	nums = (int *)malloc(sizeof(int) * size);
	i = 1;
	j = 0;
	ac_size = 0;
	if (!nums)
		return (NULL);
	while (av[i])
	{
		j = 0;
		split_str = ft_split(av[i], ' ');
		while (split_str[j])
		{
			nums[ac_size++] = ft_atoi(split_str[j++]);
		}
		free_str(split_str);
		i++;
	}
	return (nums);
}
