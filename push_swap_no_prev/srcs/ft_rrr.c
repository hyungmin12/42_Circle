/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:14:55 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/28 18:03:16 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra : reverse rotate a - 스택 a의 원소를 한 칸씩 아래로 옮깁니다. 스택의 마지막 원소는 맨 첫 번째 원소가 됩니다.

void ft_rra(t_info *info)
{
    t_num *tmp;

    tmp = info->bottom_a;
    if (info->size_a <= 1)
        return ;
	tmp = info->bottom_a;
	info->bottom_a = info->bottom_a->prev;
	info->bottom_a->next = NULL;
	info->top_a->prev = tmp;
	tmp->next = info->top_a;
	info->top_a = tmp;
	info->top_a->prev = NULL;

    // printf("top == %d , bottom == %d\n",info->top_a->content, info->bottom_a->content);
    // printf("top[0] == %d\n, top[1] == %d\n,top[2] == %d\n,top[3] == %d\n,top[4] == %d\n",
    // info->top_a->content,info->top_a->next->content,info->top_a->next->next->content,info->top_a->next->next->next->content,info->top_a->next->next->next->next->content);
    ft_putstr("rra\n");
}

void ft_rrb(t_info *info)
{
    t_num *tmp;

	if (info->size_b < 2)
	{
		return ;
	}
	tmp = info->bottom_b;
	info->bottom_b = info->bottom_b->prev;
	info->bottom_b->next = NULL;
	info->top_b->prev = tmp;
	tmp->next = info->top_b;
	info->top_b = tmp;
	info->top_b->prev = NULL;

    ft_putstr("rrb\n");
}

void ft_rrr(t_info *info)
{
    t_num *tmp;

    tmp = info->bottom_a;
    if (info->size_a <= 1 || info->size_b <= 1)
        return ;
	tmp = info->bottom_a;
	info->bottom_a = info->bottom_a->prev;
	info->bottom_a->next = NULL;
	info->top_a->prev = tmp;
	tmp->next = info->top_a;
	info->top_a = tmp;
	info->top_a->prev = NULL;
	tmp = info->bottom_b;
	info->bottom_b = info->bottom_b->prev;
	info->bottom_b->next = NULL;
	info->top_b->prev = tmp;
	tmp->next = info->top_b;
	info->top_b = tmp;
	info->top_b->prev = NULL;
    ft_putstr("rrr\n");
}