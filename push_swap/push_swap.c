/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:23:14 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/30 23:54:50 by hyyoo            ###   ########.fr       */
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
    t_info *rt;

    stack_a = NULL;
    rt = (t_info *)malloc(sizeof(t_info));
    rt->array = NULL;
    rt->size_a = 0;
    stack_a = ft_init_stack();
    rt->top_a = stack_a;
    rt->bottom_a = stack_a;
    return (rt);
}
t_num   *ft_init_stack_b(int data)
{
    t_num	*rt;

	rt = NULL;
	rt = (t_num *)malloc(sizeof(t_num));
	rt->prev = NULL;
	rt->content = data;
	rt->next = NULL;
	return (rt);
}

void    ft_init_info_b(t_info *info)
{
    t_num *stack_b;

    stack_b = NULL;
    info->top_b = stack_b;
    stack_b = ft_init_stack();
    info->size_b = 0;
    info->top_b = stack_b;
    info->bottom_b = stack_b;
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
    //  t_num *tmp = info->top_a;
    // while (size)
    // {
    //     printf("stack_a == %d\n", tmp->content);
    //     tmp = tmp->next;
	// 	size--;
    // }
    free(info->bottom_a);
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
void stack_b(t_info *info);
void stack_a(t_info *info);

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
    nums = parsing(ac, av, &arr_size, nums);

    info = ft_init_info();
    ft_int_cpy(info, nums, arr_size);
    quick_sort(nums, 0, arr_size - 1);
    
    ft_change_array_to_stack(info, nums, arr_size);
    
    ft_change_array_to_zero(nums, info, arr_size);
    // int i = 0;
    // while (i < ac - 1)
    //     printf("%d\n", info->array[i++]);
    
    ft_nums_array_change_to_stack(info, arr_size);
    // ft_sort(info);


    ft_pb(info);
    ft_pb(info);
    // ft_pb(info);
    // ft_pb(info);
    // ft_pb(info);

    stack_a(info);
    printf("-----------\n");
    // printf("%d\n", info->bottom_a->prev->content);
    stack_b(info);
    printf("%d %d\n", info->size_a, info->size_b);
    system("leaks push_swap");
    
    return 0;
}