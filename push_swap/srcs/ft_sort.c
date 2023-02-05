/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:08:24 by hyyoo             #+#    #+#             */
/*   Updated: 2023/02/05 18:19:13 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack_b(t_info *info)
{
	t_num *tmp;

	tmp = info->top_b;
	while (info->size_b)
	{
		tmp = tmp->next;
		free(tmp);
		info->size_b--;
	}
	free(tmp->next);
}

// void   max_top(t_info *info)
// {
// 	int i = 0;
// 	int max;
// 	t_num *tmp;

// 	max = info->size_b - 1;
// 	tmp = info->top_b;
// 	while(i < info->size_b)
// 	{
// 		if (tmp->content == max)
// 			ft_ra(info, "ra\n");
// 		else
// 			tmp = tmp->next;
// 		i++;
// 	}
// }


void    max_top(t_info *info)
{
    int     i;
    int     max;
    t_num  *node;
	
    i = 0;
    max = info->size_b - 1;
    node = info->top_b;
    while (node != NULL)
    {
        if(node->content == max)
        {
            if ((int)(info->size_b / 2) < i)
            {
                while (i < info->size_b)
                {
                    ft_rrb(info, "rrb\n");
                    i++;
                }
                return ;
            }
            else
            {
                while (i > 0)
                {
                    ft_rb(info, "rb\n");
                    i--;
                }
                return ;
            }
        }
        node = node->next;
        i++;
    }
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
			ft_rb(info, "rb\n");
			i++;
		}
		// else if (info->top_a->content > (i + chunk))
		// {
		// 	if ((info->size_a / 2) < i)
		// 		ft_rra(info, "rra\n");
		// 	else
		// 		ft_ra(info, "ra\n");
		// }
		else if (info->top_a->content > (i + chunk))
		{
			if (i < info->size_a / 2 && i >= 0)
				ft_rra(info, "rra\n");
			else
				ft_ra(info, "ra\n");
		}
	}
}

void	b_to_a(t_info *info)
{
	// int	length;

	// length = info->size_b - 1;
	while (info->size_b != 0)
	{
		max_top(info);
		ft_pa(info);
		// length--;
	}
}

void ft_sort_every_nums(t_info *info)
{
		int chunk;
		// chunk = 0.000000053 * info->size_a * info->size_a + 0.03 * info->size_a + 14.5;
		chunk = 15;
		if (info->size_a >= 500)
			chunk = 30;
		// chunk = 15;
		// stack_a(info);
		a_to_b(info, chunk);
		// stack_b(info);
		b_to_a(info);
		// stack_a(info);
		// printf("--------------\n");
		// stack_b(info);

		// free_stack_b(info);

		// stack_b(info);
		// stack_a(info);
}