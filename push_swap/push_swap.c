/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:23:14 by hyyoo             #+#    #+#             */
/*   Updated: 2023/02/05 20:38:49 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//이제 ra rra pa pb 만들면 됨~

#include "push_swap.h"

t_num   *ft_init_stack() // 단방향
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


t_info    *ft_init_info()
{
    t_num *stack_a;
    t_info *rt;

    stack_a = NULL;
    rt = (t_info *)malloc(sizeof(t_info));
    if (!rt)
        return (NULL);
    rt->array = NULL;
    rt->size_a = 0;
    stack_a = ft_init_stack();
    rt->top_a = stack_a;
    rt->bottom_a_content = 0;
	rt->bottom_b_content = 0;
    rt->head_a = NULL;
    rt->head_b = NULL;

    return (rt);
}

void	ft_change_array_to_stack(t_info *info, int *array, int size) // 단방향
{
    t_num   *new_node;

    info->head_a = ft_init_stack();
    while (0 < size)
    {
        info->size_a++;
        new_node = ft_init_stack();
        new_node->content = array[size - 1];
        new_node->next = info->head_a->next;
        info->head_a->next = new_node;
        info->top_a = new_node;
        size--;
    }
}

void    ft_nums_array_change_to_stack(t_info *info, int arr_size)
{
    t_num *tmp;

    int i;

    i = 0;
    tmp = info->top_a;
    while(i < arr_size)
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
    {
           ft_sort_size_three(info);
    }
    else if (info->size_a == 4)
        ft_sort_size_four(info);
    else if (info->size_a == 5)
        ft_sort_size_five(info);
    else
        ft_sort_every_nums(info);
}

t_info *ft_make_info_array(t_info *info, int size)
{
    info->array = (int *)malloc(sizeof(int) * size);
    if (!info->array)
        return (NULL);
    return (info);
}

void ft_int_cpy(t_info *info, int *nums, int size)
{
    int i;

    i = 0;
    info = ft_make_info_array(info, size);
    // info->array = ft_make(info, size);
    // if (!info->array)
    //     return (NULL);
    while (i < size)
    {
        info->array[i] = nums[i];
        i++;
    }
}

void	ft_change_array_to_zero(int *nums, t_info* info, int arr_size)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < arr_size)
    {
        j = 0;
        while (j < arr_size)
        {
            if (info->array[i] == nums[j])
            {
                info->array[i] = j;
                break;                
            }
            j++;
        }
        i++;
    }
}


void	swap_arr(int *lst, int a, int b)
{
	int	tmp;

	tmp = lst[a];
	lst[a] = lst[b];
	lst[b] = tmp;
}

void quick_sort(int *arr, int start, int end)
{
    int pivot;
    int i;
    int j;
    if(start >= end) //분할된 원소가 0개이거나 1개 일때까지 함수 호출
        return;
    pivot = start; //피봇은 첫 번째 원소
    i = pivot + 1; //i는 피봇 다음원소
    j = end; //j는 마지막 원소
    while(i<=j)
    {
        while(i<=end && arr[i]<=arr[pivot]) //피봇 보다 큰 값 만날 때 까지
            ++i;
        while(j>start && arr[j]>=arr[pivot]) //피봇 보다 작은 값 만날 때 까지
            --j;
        if(i>=j) //위에서 계산된 i와 j가 만나거나 엇갈리면 종료
            break;
        swap_arr(arr, i, j); //두 원소 교환
    }
    swap_arr(arr, j, pivot); //피봇 정렬 완료
    quick_sort(arr, start, j-1); //피봇 중심으로 왼쪽부분 분할
    quick_sort(arr, j+1, end); //피봇 중심으로 오른쪽부분 분할
}

int main(int ac, char **av)
{
    int arr_size;
    int *nums;
    t_info *info;
    
    nums = NULL;
    if (ac < 2)
    {
        ft_error_msg("Error\n");
    }
    nums = parsing(av, &arr_size, nums);
    info = ft_init_info();
    ft_int_cpy(info, nums, arr_size);
    quick_sort(nums, 0, arr_size - 1);
    ft_change_array_to_zero(nums, info, arr_size);
    free(nums);
    ft_change_array_to_stack(info, info->array, arr_size);
    
    ft_sort(info);
    system("leaks push_swap");
    return 0;
}