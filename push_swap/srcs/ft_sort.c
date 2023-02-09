/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:08:24 by hyyoo             #+#    #+#             */
/*   Updated: 2023/02/09 17:31:49 by yuhyeongmin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	max_top_utils(t_info *info, int *i)
{
	if ((int)(info->size_b / 2) < *i)
	{
		while (*i < info->size_b)
		{
			ft_rrb(info, "rrb\n");
			(*i)++;
		}
		return ;
	}
	else
	{
		while (*i > 0)
		{
			ft_rb(info, "rb\n");
			(*i)--;
		}
		return ;
	}
}

void	max_top(t_info *info)
{
	t_num	*node;
	int		max;
	int		i;

	i = 0;
	max = info->size_b - 1;
	node = info->top_b;
	while (node != NULL)
	{
		if (node->content == max)
		{
			max_top_utils(info, &i);
		}
		node = node->next;
		i++;
	}
}

void	a_to_b(t_info *info, int chunk)
{
	int	i;

	i = 0;
	while (info->size_a != 0)
	{
		if (info->top_a->content <= i)
		{
			ft_pb(info);
			i++;
		}
		else if (info->top_a->content > i && info->top_a->content <= i + chunk)
		{
			ft_pb(info);
			ft_rb(info, "rb\n");
			i++;
		}
		else if (info->top_a->content > (i + chunk))
		{
			if (i < info->size_a / 2 && i >= 0)
				ft_rra(info, "rra\n");
			else
				ft_ra(info, "ra\n");
		}
	}
}

void	b_to_a(t_info *info)
{
	while (info->size_b != 0)
	{
		max_top(info);
		ft_pa(info);
	}
}

void	ft_sort_every_nums(t_info *info)
{
	int	chunk;

	chunk = 0.000000053 * info->size_a
		* info->size_a + 0.03 * info->size_a + 14.5;
	a_to_b(info, chunk);
	b_to_a(info);
}
