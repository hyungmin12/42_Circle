/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:50:16 by hyyoo             #+#    #+#             */
/*   Updated: 2023/02/09 16:24:37 by yuhyeongmin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_info *info)
{
	int	tmp;

	tmp = 0;
	if (info->size_a < 2)
		return ;
	tmp = info->top_a->content;
	info->top_a->content = info->top_a->next->content;
	info->top_a->next->content = tmp;
	ft_putstr("sa\n");
}

void	ft_sb(t_info *info)
{
	int	tmp;

	tmp = 0;
	if (info->size_b < 2)
		return ;
	tmp = info->top_b->content;
	info->top_b->content = info->top_b->next->content;
	info->top_b->next->content = tmp;
	ft_putstr("sb\n");
}

void	ft_ss(t_info *info)
{
	int	tmp;

	tmp = 0;
	if (info->size_a < 2 || info->size_b < 2)
		return ;
	tmp = info->top_a->content;
	info->top_a->content = info->top_a->next->content;
	info->top_a->next->content = tmp;
	tmp = info->top_b->content;
	info->top_b->content = info->top_b->next->content;
	info->top_b->next->content = tmp;
	ft_putstr("ss\n");
}
