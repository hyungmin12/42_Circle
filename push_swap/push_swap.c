/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:23:14 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/24 20:25:14 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1. 인자 중복 검사
// 2. 정수인지
// 3. 정수 범위인지
// 3. 띄어쓰기 포함인지

#include "push_swap.h"

t_num   *ft_init_stack()
{
	t_num	*rt;

	rt = NULL;
	rt = (t_num *)malloc(sizeof(t_num));
	rt->prev = NULL;
	rt->content = 0;
	rt->next = NULL;
	return (rt);
}

t_info    *ft_init_info()
{
    t_num *stack_a;
    t_num *stack_b;
    t_info *rt;

    stack_a = NULL;
    stack_b = NULL;
    rt = (t_info *)malloc(sizeof(t_info));
    rt->array = NULL;
    rt->size_a = 0;
    rt->size_b = 0;
    stack_a = ft_init_stack();
    stack_b = ft_init_stack();
    rt->top_a = stack_a;
    rt->top_b = stack_b;
    rt->bottom_a = stack_a;
    rt->bottom_b = stack_b;
    rt->p1 = 0;
    rt->p2 = 0;
    return (rt);
}

void	ft_change_array_to_stack(t_info *info, int *array, int size)
{
    // 첫 시작을 바텀이 가르키고 있다가 뉴 노드를 연결하면 서 뒤로 밀림. 탑과 바텀 모두 stack_a의 구조체를 가지고 있으니
    // 바텀이 맨 뒤쪽을 가르키고 있고 자연스레 탑은 밀리기 전을 가르키고 있어서 탑을 지키고 있음.
    t_num   *new_node;
    int i;

    i = 0;
    while (i < size)
    {
        info->size_a++;
        new_node = ft_init_stack();
        info->bottom_a->content = array[i++];
        info->bottom_a->next = new_node;
        new_node->prev = info->bottom_a;
        info->bottom_a = new_node;
    }
	info->bottom_a = info->bottom_a->prev;
    free(info->bottom_a);
}

void ft_sort_every_nums(t_info *info)
{
        ft_make_pibot(info);
}

void ft_sort(t_info *info)
{
	if (info->size_a == 2)
	{
		if (info->top_a->content > info->top_a->next->content)
			ft_sa(info);
	}
    if (info->size_a == 3)
        ft_sort_size_three(info);
    // if (info->size_a > 3)
    else
        ft_sort_every_nums(info);
}

//
// void	ft_sort_big(t_info *info)
// {
// 	int	a;
// 	int	b;

// 	ft_sort_three_division(info);
// 	while (info->size_a > 3)
// 		ft_pb(info);
// 	if (info->size_a == 2)
// 	{
// 		if (info->top_a->content > info->top_a->next->content)
// 			ft_sa(info);
// 	}
// 	if (info->size_a == 3)
// 		ft_sort_more_than_three(info);
// 	while (info->size_b)
// 	{
// 		a = 0;
// 		b = 0;
// 		get_min_rotate(info, &a, &b);
// 		ft_rotate_same(info, &a, &b);
// 		ft_rotate_a(info, a);
// 		ft_rotate_b(info, b);
// 		ft_pa(info);
// 	}
// 	ft_sort_big_last(info);
// }
//
int main(int ac, char **av)
{
    int arr_size;
    int *nums;
    t_info *info;
    
    // info = NULL;
    nums = NULL;
    if (ac < 2)
    {
        ft_error_msg("ac error");
    }
    nums = parsing(ac, av, &arr_size, nums);
    info = ft_init_info();
    ft_change_array_to_stack(info, nums, arr_size);
    info->array = nums;
    ft_sort(info);
    
    // printf("t a %d, t b %d,\n", info->top_a->content, info->top_b->content);
    // printf("top_a == %d, top_a->next == %d, top_a->prev == \n", info->top_a->content, info->top_a->next->content);
    // printf("bottom_a == %d ,bottom_a->next == %d, bottom_a->prev == %d\n ",info->bottom_a->content, info->bottom_a->next->content, info->bottom_a->prev->content);
    // printf("bottom_a->next->next->content == %d\n", info->bottom_a->next->next->content);
    return 0;
}