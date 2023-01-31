/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:05:35 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/31 16:32:41 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ra : rotate a - 스택 a의 원소를 한 칸씩 위로 옮깁니다. 스택의 첫 번째 원소는 맨 마지막 원소가 됩니다.


void    ft_list_add_back(t_info *info, t_num *stack, int a_or_b, int data)
{
    t_num *tmp;
    t_num *new;

    new = ft_init_stack();
    tmp = stack;
    while (tmp != NULL)
    {
        tmp = tmp->next;
        if (tmp->next == NULL)
            break;
    }
    tmp->next = new;
    new->content = data;
    if (a_or_b == 1)
        info->size_b++;
    else
        info->size_a++;
}

void    ft_list_add_front(t_info *info, t_num *stack, int data)
{
    t_num *new;

    new = ft_init_stack();
    new->next = info->head->next;
    info->head->next = new;
    stack = new;
    stack->content = data;
}

// a  h->a->a->a->a

// void    ft_del_front(t)


void    ft_ra(t_info *info)
{
    ft_list_add_back(info ,info->top_a,0, 42);
    ft_list_add_front(info,info->top_a, 42);
    // printf("%d\n", tmp->content);
    
    // info->head->next = info->top_a->next;

    
    ft_putstr("ra\n");
}

// void    ft_rb(t_info *info)
// {
//     t_num *tmp;

//     tmp = info->top_b;
//     if(info->size_b <= 1)
//         return ;
//     info->top_b = info->top_b->next;
//     info->top_b->prev = NULL;
//     info->bottom_b->next = tmp;
//     tmp->prev = info->bottom_b;
//     info->bottom_b->next = tmp;
//     info->bottom_b = info->bottom_b->next;
//     info->bottom_b->next = NULL;
//     ft_putstr("rb\n");
// }

// void    ft_rr(t_info *info)
// {
//     t_num *tmp;

//     tmp = info->top_a;
//     if (info->size_a <= 1 || info->size_b <= 1)
//         return ;
//     info->top_a = info->top_a->next;
//     info->top_a->prev = NULL;
//     info->bottom_a->next = tmp;
//     tmp->prev = info->bottom_a;
//     info->bottom_a->next = tmp;
//     info->bottom_a = info->bottom_a->next;
//     info->bottom_a->next = NULL;
//     info->top_b = info->top_b->next;
//     info->top_b->prev = NULL;
//     info->bottom_b->next = tmp;
//     tmp->prev = info->bottom_b;
//     info->bottom_b->next = tmp;
//     info->bottom_b = info->bottom_b->next;
//     info->bottom_b->next = NULL;
//     ft_putstr("rr\n");
// }