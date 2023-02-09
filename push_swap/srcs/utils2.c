/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:36:44 by hyyoo             #+#    #+#             */
/*   Updated: 2023/02/09 16:32:11 by yuhyeongmin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_change_array_to_stack(t_info *info, int *array, int size)
{
	t_num	*new_node;

	info->head_b = ft_init_stack();
	while (0 < size)
	{
		if (info->size_a == 0)
			info->head_a = ft_init_stack();
		info->size_a++;
		new_node = ft_init_stack();
		new_node->content = array[size - 1];
		new_node->next = info->head_a->next;
		info->head_a->next = new_node;
		info->top_a = new_node;
		size--;
	}
}

void	ft_nums_array_change_to_stack(t_info *info, int arr_size)
{
	t_num	*tmp;
	int		i;

	tmp = info->top_a;
	i = 0;
	while (i < arr_size)
	{
		tmp->content = info->array[i];
		tmp = tmp->next;
		i++;
	}
	free(tmp);
}

t_info	*ft_make_info_array(t_info *info, int size)
{
	info->array = (int *)malloc(sizeof(int) * size);
	if (!info->array)
		return (NULL);
	return (info);
}

void	ft_int_cpy(t_info *info, int *nums, int size)
{
	int	i;

	i = 0;
	info = ft_make_info_array(info, size);
	while (i < size)
	{
		info->array[i] = nums[i];
		i++;
	}
}

void	ft_change_array_to_zero(int *nums, t_info *info, int arr_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < arr_size)
	{
		j = 0;
		while (j < arr_size)
		{
			if (info->array[i] == nums[j])
			{
				info->array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}
