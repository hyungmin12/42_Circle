/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:23:14 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/23 15:40:47 by yuhyeongmin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1. 인자 중복 검사
// 2. 정수인지
// 3. 정수 범위인지
// 3. 띄어쓰기 포함인지

#include "push_swap.h"

// t_info	*ft_info_new(void)
// {
// 	t_numbers	*stack_a;
// 	t_info		*new_mem;

// 	new_mem = NULL;
// 	new_mem = (t_info *)malloc(sizeof(t_info));
// 	stack_a = ft_stack_new();
// 	new_mem->array = NULL;
// 	new_mem->size_a = 0;
// 	new_mem->top_a = stack_a;
// 	new_mem->bottom_a = stack_a;
// 	new_mem->size_b = 0;
// 	return (new_mem);
// }

int main(int ac, char **av)
{
    int arr_size;
    int *nums;
    // t_info *info;
    
    nums = NULL;
    if (ac < 2)
    {
        ft_error_msg("ac error");
    }
    parsing(ac, av, &arr_size, nums);
}