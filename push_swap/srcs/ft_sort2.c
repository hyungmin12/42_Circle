/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:19:32 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/29 22:47:55 by hyyoo            ###   ########.fr       */
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
        ft_sa(info);
        ft_ra(info);
    }
    if (t > m && t > b && m < t && m > b && b < t && b < m)
    {
        ft_sa(info);
        ft_rra(info);
    }
}

void	ft_sort_size_four(t_info *info)
{
	int	index;

    index = 0;
	// index = get_index(info, 1, 1); // 이거 써야함.
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
	// printf("%d\n", info->top_b->next->content);
}

void   max_top(t_info *info)
{
    int     i;
    int     max;
    t_num  *node;
    i = 0;
	node = info->top_b;
    max = info->size_b;
    while (node != NULL)
    {
        if(node->content == max)
        {
		// printf("%d", node->content);
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
		// printf("tmp = %d, bottom== %d\n", tmp->content, info->bottom_a->content);
		tmp = tmp->next;
		index++;
	}
	return (-1);
}

void	b_from_a(t_info *info)
{
	int	max;
	int	mid;
	int	max_index;
	
    max = info->size_b;
	while (max > 0)
	{
		max_index = get_index(info, info->size_b);
		mid = max / 2;
		if (max_index <= mid)
			while ((max_index--) > 0)
                ft_rb(info);
		else
			while ((max_index++) < max)
                ft_rrb(info);
        ft_pa(info);
		max--;
	}
        
    //     printf("--------------------------\n");
		
    //     t_num *tmp;
	// 	tmp = info->top_a;
	// 	while (tmp != NULL)
	// 	{
	// 		printf("a == %d", tmp->content);
	// 		tmp = tmp->next;
	// 	}
	// 	printf("\n");
	// 	tmp = info->top_b;
	// 	while (tmp != NULL)
	// 	{
	// 		printf("b == %d", tmp->content);
	// 		tmp = tmp->next;
	// 	}
	// 	printf("\n");
	// }
	// while (info->top_b == NULL)
	// {
	// 	free(info->top_b);
	// 	info->top_b = info->top_b->next;
	// 	printf("%d\n", info->top_b->content);
	// }
	// // free(info->top_b);
	// printf("%d\n", info->top_b->content);
}


// void	ft_sort_more_than_five(t_info *info)
// {
// 	int	index;
// 	int	chunk;
//     // info->bottom_a->next->prev = NULL;
//     // info->bottom_a->next = NULL;
//     // info->bottom_b->next->prev = NULL;
//     // info->bottom_b->next = NULL;
// 	// chunk = 0.000000053 * info->size_a * info->size_a + 0.03 * info->size_a + 14.5;
//     chunk = 15;
// 	index = 0;
//     if (info->size_a > 499)
//         chunk = 30;
// 	while (info->size_a > 0)
// 	{
// 		if (info->top_a->content <= index)
// 		{
//             ft_pb(info);
// 			index++;
// 		}
// 		else if (info->top_a->content <= index + chunk)
// 		{
// 			ft_pb(info);
// 			ft_rb(info);
// 			index++;
// 		}
// 		else
// 			ft_ra(info);

//         // printf("--------------------------\n");
		
//         // t_num *tmp;
// 		// tmp = info->top_b;
// 		// while (tmp != NULL)
// 		// {
// 		// 	printf("%d", tmp->content);
// 		// 	tmp = tmp->next;
// 		// }
// 		// printf("\n");
// 	}
//     b_from_a(info);
// }
void print_a(t_info *info, int ac)
{
	int i = 0;
	
	while (i++ < ac)
	{
		printf("%d\n", info->top_a->content);
		info->top_a = info->top_a->next;
	}
}

void print_b(t_info *info, int ac)
{
	// int i = 0;
	
	(void)ac;
	while (info->top_b->content != info->bottom_b->content)
	{
		printf("%d\n", info->top_b->content);
		info->top_b = info->top_b->next;
	}
}

void	a_to_b(t_info *info, int chunk, int i)
{
	int	length;

	length = info->size_a;
	// printf("%d", info->size_a);
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
	// print_b(info, 7);
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
	// int chunk = 15;
	// if (info->size_a >= 500)
	// 	chunk = 30;
    // ft_sort_more_than_five(info);
	a_to_b(info, 29, 0);
	b_to_a(info);
}