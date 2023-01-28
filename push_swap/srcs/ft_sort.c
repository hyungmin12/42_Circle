/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:08:24 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/27 23:27:20 by hyyoo            ###   ########.fr       */
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
}

int	get_index(t_info *info, int data, int a_or_b)
{
	t_num	*tmp;
	int		index;


    index = 0;
    tmp = info->top_b;
    if (a_or_b == 1)
	{
        tmp = info->top_a;
    }
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

	index = get_index(info, 1, 1);
	if (index < (info->size_a / 2))
		while (info->top_a->content != 1)
			ft_ra(info);
	else
		while (info->top_a->content != 1)
			ft_rra(info);
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
		if (info->top_a->content == 1)
			ft_pb(info);
		else if (info->top_a->content == 2)
			ft_pb(info);
        else
			ft_ra(info);
	}
	ft_sb(info);
	if_case_two(info, 1, 0);
	ft_sort_size_three(info);
    ft_pa(info);
    ft_pa(info);
}
void    max_top(t_info *info)
{
    int     i;
    int     max;
    t_num  *node;
    i = 0;
	int j = 0;
    max = info->size_b - 1;
    node = info->top_b;
	int size = info->size_b;
	// info->bottom_b->next = NULL;
    while (j++ < size)
    {
        if(node->content == max)
        {
            if ((int)(info->size_b / 2) < i)
            {
                while (i < info->size_b)
                {
                    ft_rrb(info); // 절반보다 윗쪽이면
                    i++;
                }
                return ;
            }
            else
            {
                while (i > 0)
                {
					ft_rb(info); // 절반보다 아래면
                    i--;
                }
                return ;
            }
        }
        node = node->next;
        i++;
    }
	printf("%d\n", max);
}

void	a_to_b(t_info *info, int chunk, int i)
{
	int	length;

	length = info->size_a - 1;
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
			if (i < info->size_a / 2 && i >= 0)
				ft_rra(info);
			else
				ft_ra(info);
		}
		length--;
	}
}

void	b_to_a(t_info *info)
{
	int	length;

	length = info->size_b - 1;
	while (info->size_b != 0)
	{
		max_top(info);
		ft_pa(info);
		length--;
	}
}

void ft_sort_every_nums(t_info *info)
{
	// if (info->size_a >= 500)
		a_to_b(info, 15, 1);
		b_to_a(info);
}