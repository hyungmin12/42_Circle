/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:05:35 by hyyoo             #+#    #+#             */
/*   Updated: 2023/02/07 16:12:34 by hyyoo            ###   ########.fr       */
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
    // free(tmp);
    // free(new);
    if (a_or_b == 1)
        info->size_b++;
    else
        info->size_a++;
}

void    ft_list_add_front_a(t_info *info, int data)
{
    t_num *new;

    new = ft_init_stack();
    if (info->size_a == 0)
    {
        info->head_a = ft_init_stack();
        info->head_a->next = info->top_a;
        info->top_a = ft_init_stack();
        info->head_a->next = info->top_a;
        info->top_a->next = NULL;
        info->top_a->content = data;
    }
    else
    {
        new->next = info->top_a;
        info->head_a->next = new;
        new->content = data;
        info->top_a = new;
    }
    info->size_a++;
}

void    ft_list_add_front_b(t_info *info, int data)
{
    t_num *new;

    new = ft_init_stack();
    if (info->size_b == 0)
    {
        info->head_b = ft_init_stack();
        info->head_b->next = info->top_b;
        info->top_b = ft_init_stack();
        info->head_b->next = info->top_b;
        info->top_b->next = NULL;
        info->top_b->content = data;
    }
    else
    {
        new->next = info->top_b;
        info->head_b->next = new;
        new->content = data;
        info->top_b = new;
    }
    info->size_b++;
}

void ft_remove_front_a(t_info *info)
{
    // t_num *tmp;
    
    // if (info->size_a == 0)
    //     return ;
    // tmp = info->top_a->next;
    // info->head_a->next = tmp;
    // free(info->top_a);
    // info->top_a = tmp;
    // // tmp = NULL;
    // // free(tmp);
    // info->size_a--;

    if (info->size_b == 0)
        return ;
    info->head_a->next = info->top_a->next;
    free(info->top_a);
    info->top_a = info->top_a->next;

    info->size_a--;
}

void ft_remove_front_b(t_info *info)
{
    // t_num *tmp;
    
    // if (info->size_b == 0)
    //     return ;
    // tmp = info->top_b->next;
    // info->head_b->next = tmp;
    // free(info->top_b);
    // info->top_b = tmp;
    // // tmp = NULL;

    // info->size_b--;
    
    if (info->size_b == 0)
        return ;
    info->head_b->next = info->top_b->next;
    free(info->top_b);
    info->top_b = info->top_b->next;

    info->size_b--;
}

void ft_remove_back_a(t_info *info)
{
    t_num *pri = info->head_a;
	t_num *temp = pri->next;

	// 현재 노드가 없을 경우
	if(pri == NULL)
		return;

	// 현재 노드가 한 개일 경우
	if(pri->next == NULL)
	{
		info->head_a = NULL;
		free(pri);
	}
	else // 노드가 2개 이상일 경우
	{
		while(temp->next != NULL)
		{
			pri = temp;
			temp = temp->next;
		}
		pri->next = NULL;
		free(temp);
	}
    info->size_a--;
}

void ft_remove_back_b(t_info *info)
{
    t_num *pri = info->head_b;
	t_num *temp = pri->next;

	// 현재 노드가 없을 경우
	if(pri == NULL)
		return;

	// 현재 노드가 한 개일 경우
	if(pri->next == NULL)
	{
		info->head_b = NULL;
		free(pri);
	}
	else // 노드가 2개 이상일 경우
	{
		while(temp->next != NULL)
		{
			pri = temp;
			temp = temp->next;
		}
		pri->next = NULL;
		free(temp);
	}
    info->size_b--;
}

void    ft_pb(t_info *info)
{
    int i;

    if (info->size_a == 0)
        return ;
    i = info->top_a->content;
    ft_list_add_front_b(info, i);
    ft_remove_front_a(info);
    ft_putstr("pb\n");
}

void    ft_pa(t_info *info)
{
    int i;

    if (info->size_b == 0)
        return ;
    i = info->top_b->content;
    ft_list_add_front_a(info, i);
    ft_remove_front_b(info);
    ft_putstr("pa\n");
}

void    ft_ra(t_info *info, char *msg)
{
    int i;
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

void    ft_rb(t_info *info, char *msg)
{
    int i;

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

void    ft_rr(t_info *info)
{
    ft_ra(info, NULL);
    ft_rb(info, NULL);
    ft_putstr("rr\n");
}

void    ft_rra(t_info *info, char *msg)
{
	t_num *tmp;

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

void    ft_rrb(t_info *info, char *msg)
{
	t_num *tmp;

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

void    ft_rrr(t_info *info)
{
    ft_rra(info, NULL);
    ft_rrb(info, NULL);
    ft_putstr("rrr\n");
}