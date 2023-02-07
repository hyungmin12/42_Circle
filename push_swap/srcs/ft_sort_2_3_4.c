/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2_3_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:43:37 by hyyoo             #+#    #+#             */
/*   Updated: 2023/02/07 21:21:17 by yuhyeongmin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_bottom_a(t_info *info)
{
	t_num *tmp;

	tmp = info->top_a;
	while (tmp != NULL)
	{
        info->bottom_a_content = tmp->content;
		tmp = tmp->next;
	}
	// free(tmp);
}

void ft_sort_size_three(t_info *info)
{
    int t;
    int m;
    int b;

	get_bottom_a(info);
    t = info->top_a->content;
    m = info->top_a->next->content;
    b = info->bottom_a_content;
    
    if (t < m && t < b && m > b && m > t && b > t && b < m)
    {
        ft_sa(info);
        ft_ra(info, "ra\n");
    }
    if (t > m && t < b && m < t && m < b && b > t && b > m)
        ft_sa(info);
    if (t < m && t > b && m > t && m > b && b < m && b < t)
    { 
        ft_rra(info, "rra\n");
    }
    if (t > m && t > b && m < t && m < b && b > m && b < t)
    {
        ft_ra(info, "ra\n");
    }
    if (t > m && t > b && m < t && m > b && b < t && b < m)
    {
        ft_sa(info);
        ft_rra(info, "rra\n");
    }
}

int	get_index(t_info *info, int data)
{
	t_num	*tmp;
	int		index;

	index = 0;
	tmp = info->top_a;
	while (tmp != NULL)
	{
		if (tmp->content == data)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (-1);
}

void	ft_sort_size_four(t_info *info)
{
	int	index;

	index = get_index(info, 0);
	if (index < (info->size_a / 2))
		while (info->top_a->content != 0)
			ft_ra(info, "ra\n");
	else
		while (info->top_a->content != 0)
			ft_rra(info, "rra\n");
	ft_pb(info);
	ft_sort_size_three(info);
    ft_pa(info);
}

void	if_case_two(t_info *info, int a_b, int sort)
{
	if (sort == 1)
	{
		if (info->top_b->content > info->top_b->next->content)
		{
			if (a_b == 0)
				ft_sa(info);
			else if (a_b == 1)
				ft_sb(info);
		}
	}
	else
	{
		if (info->top_b->content < info->top_b->next->content)
		{
			if (a_b == 0)
				ft_sa(info);
			else if (a_b == 1)
				ft_sb(info);
		}
	}
}

void	ft_sort_size_five(t_info *info)
{
	while (info->size_a > 3)
	{
		if (info->top_a->content == 0)
			ft_pb(info);
		else if (info->top_a->content == 1)
			ft_pb(info);
        else
			ft_ra(info, "ra\n");
	}
	ft_sb(info);
	if_case_two(info, 1, 0);
	ft_sort_size_three(info);
    ft_pa(info);
    ft_pa(info);
}