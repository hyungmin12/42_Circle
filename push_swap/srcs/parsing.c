/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:28:52 by hyyoo             #+#    #+#             */
/*   Updated: 2023/02/09 17:47:00 by yuhyeongmin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	check_is_sorted(int *nums, int size)
{
	int	check;
	int	i;
	int	j;

	check = 0;
	j = 0;
	i = 0;
	while (i < size)
	{
		if (nums[j] < nums[j + 1] && j < size - 1)
		{
			check++;
			j++;
		}
		i++;
	}
	if (check == size - 1)
	{
		free(nums);
		ft_error_msg();
	}
}

void	check_is_overlap(int *nums, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nums[i] == nums[j])
			{
				free(nums);
				ft_error_msg();
				return ;
			}
			j++;
		}
		i++;
	}
}

int	*parsing(char **av, int *arr_size, int *nums)
{
	int	size;

	check_is_int(av);
	*arr_size = get_array_size(av);
	size = *arr_size;
	nums = get_num_array(av, size);
	check_is_sorted(nums, size);
	check_is_overlap(nums, size);
	return (nums);
}
