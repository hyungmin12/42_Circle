/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:23:14 by hyyoo             #+#    #+#             */
/*   Updated: 2023/02/09 16:50:29 by yuhyeongmin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_info *info)
{
	if (info->size_a == 2)
	{
		if (info->top_a->content > info->top_a->next->content)
			ft_sa(info);
	}
	if (info->size_a == 3)
	{
		ft_sort_size_three(info);
	}
	else if (info->size_a == 4)
		ft_sort_size_four(info);
	else if (info->size_a == 5)
		ft_sort_size_five(info);
	else if (info->size_a > 5)
		ft_sort_every_nums(info);
}

void	swap_arr(int *lst, int a, int b)
{
	int	tmp;

	tmp = lst[a];
	lst[a] = lst[b];
	lst[b] = tmp;
}

void	quick_sort(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	if (start >= end)
		return ;
	pivot = start;
	i = pivot + 1;
	j = end;
	while (i <= j)
	{
		while (i <= end && arr[i] <= arr[pivot])
			++i;
		while (j > start && arr[j] >= arr[pivot])
			--j;
		if (i >= j)
			break ;
		swap_arr(arr, i, j);
	}
	swap_arr(arr, j, pivot);
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}

int	main(int ac, char **av)
{
	t_info	*info;
	int		arr_size;
	int		*nums;

	nums = NULL;
	if (ac < 2)
		ft_error_msg("Error\n");
	nums = parsing(av, &arr_size, nums);
	info = ft_init_info();
	ft_int_cpy(info, nums, arr_size);
	quick_sort(nums, 0, arr_size - 1);
	ft_change_array_to_zero(nums, info, arr_size);
	ft_change_array_to_stack(info, info->array, arr_size);
	free(nums);
	free(info->array);
	ft_sort(info);
	free_stack(&info->top_a);
	free_stack(&info->top_b);
	free(info->head_a);
	free(info->head_b);
	free(info);
	return (0);
}
