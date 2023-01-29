/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:23:14 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/28 20:59:14 by hyyoo            ###   ########.fr       */
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
	// rt->prev = NULL;
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
        info->top_a->content = array[size--];
        info->top_a->next = new_node;
        // new_node->prev = info->bottom_a;
        info->top_a = new_node;
    }
    free(info->top_a);
}

int *ft_bubble_sort(int *nums, int size)
{
    int i;
    int j;
    int temp;

    i = 0;
    j = 0;
    temp = 0;
    
    while (i < size - 1)
    {
        while (j < size - 1 - i)
        {
            if (nums[j] > nums[j + 1])
            {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
            j++;
        }
        j = 0;
        i++;
    }

    return (nums);
}
void    ft_nums_array_change_to_stack(t_info *info)
{
    t_num *tmp;

    int i;

    i = 0;
    tmp = info->top_a;
    while(i < info->size_a)
    {
        tmp->content = info->array[i];
        tmp = tmp->next;
        i++;
    }
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
    else if (info->size_a == 4)
        ft_sort_size_four(info);
    else if (info->size_a == 5)
        ft_sort_size_five(info);
    else
        ft_sort_every_nums(info);
}

void ft_int_cpy(t_info *info, int *nums, int size)
{
    int i;

    i = 0;
    info->array = (int *)malloc(sizeof(int) * size);
    while (i < size)
    {
        info->array[i] = nums[i];
        i++;
    }
}

void	ft_change_array_to_zero(int *nums, t_info* info)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < info->size_a)
    {
        j = 0;
        while (j < info->size_a)
        {
            if (info->array[i] == nums[j])
                info->array[i] = j + 1;
            j++;   
        }
        i++;
        j += i;
    }
}

int main(int ac, char **av)
{
    int arr_size;
    int *nums;
    t_info *info;
    
    nums = NULL;
    if (ac < 2)
    {
        ft_error_msg("ac error");
    }
    nums = parsing(ac, av, &arr_size, nums);
    info = ft_init_info();
    ft_int_cpy(info, nums, arr_size);
    nums = ft_bubble_sort(nums, arr_size);
    ft_change_array_to_stack(info, nums, arr_size);
    ft_change_array_to_zero(nums, info);
    ft_nums_array_change_to_stack(info);
    ft_sort(info);
           
    return 0;
}