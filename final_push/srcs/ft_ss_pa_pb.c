/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss_pa_pb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:50:16 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/31 15:51:12 by hyyoo            ###   ########.fr       */
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
