/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:05:35 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/28 18:01:32 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ra : rotate a - 스택 a의 원소를 한 칸씩 위로 옮깁니다. 스택의 첫 번째 원소는 맨 마지막 원소가 됩니다.

void    ft_ra(t_info *info)
{
    t_num *tmp;

    tmp = info->top_a;
    if (info->size_a <= 1)
        return ;
    info->top_a = info->top_a->next;
    info->top_a->prev = NULL;
    info->bottom_a->next = tmp;
    tmp->prev = info->bottom_a;
    info->bottom_a->next = tmp;
    info->bottom_a = info->bottom_a->next;
    info->bottom_a->next = NULL;
    ft_putstr("ra\n");
    
    // printf("%d , %d %d\n", info->top_a->content,info->top_a->next->content,info->bottom_a->content );

    // printf("top1 == %d, top2 == %d, top3 == %d, top4 == %d\n", 
    // info->top_a->content, info->top_a->next->content, info->top_a->next->next->content, info->top_a->prev->content);
    // printf("bottom_a == %d , top_a->next == %d\n",info->bottom_a->content, info->top_a->content);
}

void    ft_rb(t_info *info)
{
    t_num *tmp;

    tmp = info->top_b;
    if(info->size_b <= 1)
        return ;
    info->top_b = info->top_b->next;
    info->top_b->prev = NULL;
    info->bottom_b->next = tmp;
    tmp->prev = info->bottom_b;
    info->bottom_b->next = tmp;
    info->bottom_b = info->bottom_b->next;
    info->bottom_b->next = NULL;
    ft_putstr("rb\n");
}

void    ft_rr(t_info *info)
{
    t_num *tmp;

    tmp = info->top_a;
    if (info->size_a <= 1 || info->size_b <= 1)
        return ;
    info->top_a = info->top_a->next;
    info->top_a->prev = NULL;
    info->bottom_a->next = tmp;
    tmp->prev = info->bottom_a;
    info->bottom_a->next = tmp;
    info->bottom_a = info->bottom_a->next;
    info->bottom_a->next = NULL;
    info->top_b = info->top_b->next;
    info->top_b->prev = NULL;
    info->bottom_b->next = tmp;
    tmp->prev = info->bottom_b;
    info->bottom_b->next = tmp;
    info->bottom_b = info->bottom_b->next;
    info->bottom_b->next = NULL;
    ft_putstr("rr\n");
}