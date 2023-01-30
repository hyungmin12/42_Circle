/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:19:32 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/30 21:03:52 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void   max_top(t_info *info)
{
    int     i;
    int     max;
    t_num  *node;
    i = 0;
	if (i == 0)
	{
		info->top_b->content = info->size_b - 1;
	}
	node = info->top_b;
	// printf("top_b == %d\n", info->top_b->content);
    max = info->size_b - 1;
	// printf("max == %d\n", max);
    while (node != NULL)
    {
        if(node->content == max)
        {
		// printf("%d", max);
            if ((int)(info->size_b / 2) < i)
            {
                while (i < info->size_b)
                {
					ft_rrb(info);
                    i++;
                }
                return ;
            }
            else
            {
                while (i > 0)
                {
					ft_rb(info);
                    i--;
                }
                return ;
            }
        }
        node = node->next;
        i++;
    }
	// ft_pb(info); // 지우기
}

void	a_to_b(t_info *info, int chunk)
{
	int i = 0;
	
	while (info->size_a != 0)
	{ 
		if (info->top_a->content <= i)
		{
			ft_pb(info);
			i++;
		}
		else if (info->top_a->content > i && info->top_a->content <= i + chunk)
		{
			ft_pb(info);
			ft_rb(info);
			i++;
		}
		else if (info->top_a->content > (i + chunk))
		{
			// if ((info->size_a / 2) < i)
			if (i < info->size_a / 2 && i >= 0)
				ft_rra(info);
			else
				ft_ra(info);
		}
	}
}

void	b_to_a(t_info *info)
{
	int	length;

	length = info->size_b - 1;
	while (info->size_b != 0)
	{
	// printf("b_size == %d", length);
		max_top(info);
		ft_pa(info);
		length--;
	}
}


void ft_sort_every_nums(t_info *info)
{
	int chunk;
	chunk = 0.000000053 * info->size_a * info->size_a + 0.03 * info->size_a + 14.5;
	// chunk = 15;	
	// if (info->size_a >= 500)
	// {
	// 	chunk = 30;
	// }
    // ft_sort_more_than_five(info);
	a_to_b(info, chunk);
	// t_num *tmp = info->top_a;
	// while (tmp)
    // {
    //     printf("stack_a == %d\n", tmp->content);
    //     tmp = tmp->next;
    // }
    // tmp = info->top_b;
    // while (tmp)
    // {
    //     printf("stack_b == %d\n", tmp->content);
    //     tmp = tmp->next;
    // }
	// b_to_a(info);
	// t_num *tmp = info->top_a;
	// while (tmp)
    // {
    //     printf("stack_a == %d\n", tmp->content);
    //     tmp = tmp->next;
    // }
}