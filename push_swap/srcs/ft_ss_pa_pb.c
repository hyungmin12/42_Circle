/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss_pa_pb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:50:16 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/30 23:51:30 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sa(t_info *info)
{
    int tmp;

    tmp = 0;
    if (info->size_a < 2)
        return ;
    tmp = info->top_a->content;
    info->top_a->content = info->top_a->next->content;
    info->top_a->next->content = tmp;
    ft_putstr("sa\n");
    // printf("%d\n", info->top_a->content);
    // printf("%d\n", info->top_a->next->content);
}

void ft_sb(t_info *info)
{
    int tmp;

    tmp = 0;
    if (info->size_b < 2)
        return ;
    tmp = info->top_b->content;
    info->top_b->content = info->top_b->next->content;
    info->top_b->next->content = tmp;
    ft_putstr("sb\n"); 
    // printf("%d\n", info->top_a->content);
    // printf("%d\n", info->top_a->next->content);
}

void ft_ss(t_info *info)
{
    int tmp;

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

void	ft_pa(t_info *info)
{
	t_num	*tmp;

	if (info->size_b < 1)
		return ;
	tmp = info->top_b;
	if (info->size_b > 1)
	{
		info->top_b = info->top_b->next;
		info->top_b->prev = NULL;
	}
	if (info->size_a == 0)
	{
		tmp->next = NULL;
		info->top_a = tmp;
		info->bottom_a = tmp;
	}
	else
	{
		tmp->next = info->top_a;
		info->top_a->prev  = tmp;
		info->top_a = tmp;
	}
	info->size_a += 1;
	info->size_b -= 1;
    ft_putstr("pa\n");
}

void	ft_pb(t_info *info)
{
	t_num *tmp;

	// tmp = info->top_a->next;
	if (info->top_b == NULL)
		ft_init_info_b(info);
	if (info->size_a < 1)
		return ;
	info->top_b = ft_init_stack_b(info->top_a->content);
	if (info->size_a > 1)
	{
		// int tmp_con = info->top_a->content;
		tmp = info->top_a->next;
		info->top_a->next = NULL;
		info->top_a->prev = NULL;
		free(info->top_a);
		info->top_a = tmp;
		// info->top_a->prev = NULL;
		// info->bottom_a->next = NULL;
	}
	// if (info->size_b == 0)
	// {
	// 	tmp->next = NULL;
	// 	tmp->prev = NULL;
	// 	info->top_b = tmp;
	// 	info->bottom_b = tmp;
	// }
	// else
	// {
	// 	tmp->next = info->top_b;
	// 	info->top_b->prev = tmp;
	// 	info->top_b = tmp;
	// 	info->top_b->prev = NULL;
	// }
	info->size_a -= 1;
	info->size_b += 1;
    ft_putstr("pb\n");
}