/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:39:44 by hyyoo             #+#    #+#             */
/*   Updated: 2023/02/09 15:41:06 by yuhyeongmin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_num **stack_a)
{
	t_num	*last_lst;

	last_lst = *stack_a;
	if (stack_a != NULL || *stack_a != NULL)
	{
		while (*stack_a)
		{
			*stack_a = last_lst->next;
			free(last_lst);
			last_lst = *stack_a;
		}
	}
}

t_num	*ft_init_stack(void)
{
	t_num	*rt;

	rt = NULL;
	rt = (t_num *)malloc(sizeof(t_num));
	if (!rt)
		return (NULL);
	rt->next = NULL;
	rt->content = 0;
	return (rt);
}

t_info	*ft_init_info(void)
{
	t_info	*rt;

	rt = (t_info *)malloc(sizeof(t_info));
	if (!rt)
		return (NULL);
	rt->array = NULL;
	rt->size_a = 0;
	rt->top_a = NULL;
	rt->top_b = NULL;
	rt->bottom_a_content = 0;
	rt->bottom_b_content = 0;
	rt->head_a = NULL;
	rt->head_b = NULL;
	return (rt);
}
