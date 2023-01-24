/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:08:24 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/24 20:33:26 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_size_three(t_info *info)
{
    int t;
    int m;
    int b;

    t = info->top_a->content;
    m = info->top_a->next->content;
    b = info->bottom_a->content;
    if (t < m && t < b && m > b && m > t && b > t && b < m)
    {
        ft_sa(info);
        ft_ra(info);
    }
    if (t > m && t < b && m < t && m < b && b > t && b > m)
        ft_sa(info);
    if (t < m && t > b && m > t && m > b && b < m && b < t)
    {
        ft_rra(info);
    }
    if (t > m && t > b && m < t && m < b && b > m && b < t)
    {
        // ft_sa(info);
        ft_ra(info);
    }
    if (t > m && t > b && m < t && m > b && b < t && b < m)
    {
        ft_sa(info);
        ft_rra(info);
    }
        // printf("%d %d %d\n", info->top_a->content,info->top_a->next->content,info->bottom_a->content );
}

void    ft_make_pibot(t_info *info)
{
    int i;
    int j;

    j = 0;
    i = info->size_a / 3;
    info->p1 = info->array[i];
    i = i * 2;
    info->p2 = info->array[i];
    while (j < info->size_a)
    {
        if (info->top_a->content < info->p1)
	    {
	    	ft_pb(info);
	    	ft_rb(info);
	    }
	    else if (info->top_a->content < info->p2)
	    	ft_pb(info);
	    else
	    	ft_ra(info);
        j++;
    }
}