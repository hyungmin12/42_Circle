/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:11:52 by hyyoo             #+#    #+#             */
/*   Updated: 2023/02/09 16:13:14 by yuhyeongmin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_info *info)
{
	int	i;

	if (info->size_a == 0)
		return ;
	i = info->top_a->content;
	ft_list_add_front_b(info, i);
	ft_remove_front_a(info);
	ft_putstr("pb\n");
}

void	ft_pa(t_info *info)
{
	int	i;

	if (info->size_b == 0)
		return ;
	i = info->top_b->content;
	ft_list_add_front_a(info, i);
	ft_remove_front_b(info);
	ft_putstr("pa\n");
}

void	ft_ra(t_info *info, char *msg)
{
	int	i;

	if (info->size_a == 2)
		ft_sa(info);
	else if (info->size_a == 1)
		return ;
	else
	{
		i = info->top_a->content;
		ft_list_add_back(info, info->top_a, 0, i);
		ft_remove_front_a(info);
		ft_putstr(msg);
	}
}

void	ft_rb(t_info *info, char *msg)
{
	int	i;

	if (info->size_b == 2)
		ft_sb(info);
	else if (info->size_b == 1)
		return ;
	else
	{
		i = info->top_b->content;
		ft_list_add_back(info, info->top_b, 1, i);
		ft_remove_front_b(info);
		ft_putstr(msg);
	}
}

void	ft_rr(t_info *info)
{
	ft_ra(info, NULL);
	ft_rb(info, NULL);
	ft_putstr("rr\n");
}
