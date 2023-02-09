/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_and_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:06:40 by hyyoo             #+#    #+#             */
/*   Updated: 2023/02/09 16:10:03 by yuhyeongmin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_add_back(t_info *info, t_num *stack, int a_or_b, int data)
{
	t_num	*tmp;
	t_num	*new;

	new = ft_init_stack();
	tmp = stack;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			break ;
	}
	tmp->next = new;
	new->content = data;
	if (a_or_b == 1)
		info->size_b++;
	else
		info->size_a++;
}

void	ft_list_add_front_a(t_info *info, int data)
{
	t_num	*new;

	new = NULL;
	if (info->size_a == 0)
	{
		info->top_a = ft_init_stack();
		info->head_a->next = info->top_a;
		info->head_a->next = info->top_a;
		info->top_a->next = NULL;
		info->top_a->content = data;
	}
	else
	{
		new = ft_init_stack();
		new->next = info->top_a;
		info->head_a->next = new;
		new->content = data;
		info->top_a = new;
	}
	info->size_a++;
}

void	ft_list_add_front_b(t_info *info, int data)
{
	t_num	*new;

	if (info->size_b == 0)
	{
		info->head_b->next = info->top_b;
		info->top_b = ft_init_stack();
		info->head_b->next = info->top_b;
		info->top_b->next = NULL;
		info->top_b->content = data;
	}
	else
	{
		new = ft_init_stack();
		new->next = info->top_b;
		info->head_b->next = new;
		new->content = data;
		info->top_b = new;
	}
	info->size_b++;
}

void	ft_remove_front_a(t_info *info)
{
	t_num	*tmp;

	if (info->size_a == 0)
		return ;
	tmp = info->top_a->next;
	info->head_a->next = tmp;
	free(info->top_a);
	info->top_a = tmp;
	info->size_a--;
}

void	ft_remove_front_b(t_info *info)
{
	t_num	*tmp;

	if (info->size_b == 0)
		return ;
	tmp = info->top_b->next;
	info->head_b->next = tmp;
	free(info->top_b);
	info->top_b = tmp;
	info->size_b--;
}
