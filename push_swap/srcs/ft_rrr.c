/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:14:55 by hyyoo             #+#    #+#             */
/*   Updated: 2023/02/09 16:18:19 by yuhyeongmin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_info *info, char *msg)
{
	t_num	*tmp;

	tmp = info->top_a;
	while (tmp != NULL)
	{
		info->bottom_a_content = tmp->content;
		tmp = tmp->next;
	}
	if (info->size_a == 2)
		ft_sa(info);
	else if (info->size_a == 1)
		return ;
	else
	{
		ft_list_add_front_a(info, info->bottom_a_content);
		ft_remove_back_a(info);
		ft_putstr(msg);
	}
}

void	ft_rrb(t_info *info, char *msg)
{
	t_num	*tmp;

	tmp = info->top_b;
	while (tmp != NULL)
	{
		info->bottom_b_content = tmp->content;
		tmp = tmp->next;
	}
	if (info->size_b == 2)
		ft_sa(info);
	else if (info->size_b == 1)
		return ;
	else
	{
		ft_list_add_front_b(info, info->bottom_b_content);
		ft_remove_back_b(info);
		ft_putstr(msg);
	}
}

void	ft_rrr(t_info *info)
{
	ft_rra(info, NULL);
	ft_rrb(info, NULL);
	ft_putstr("rrr\n");
}
