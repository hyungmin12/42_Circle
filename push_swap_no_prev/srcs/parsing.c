/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:28:52 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/27 21:41:49 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1. 인자 중복 검사
// 2. 정수인지
// 3. 정수 범위인지
// 3. 띄어쓰기 포함인지

#include "push_swap.h"

void check_is_int(char **av)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if ((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == ' ' || av[i][j] == '-')
                j++;
            else
                ft_error_msg("is not int2");
        }
        i++;
    }
}

void check_is_sorted(int *nums, int size)
{
    int i;
    int check;
    
    i = 0;
    int j = 0;
    check = 0;
    while (i < size)
    {
        if (nums[j] < nums[j + 1] && j < size - 1)
        {
            check++; 
            j++;
        }
        i++;
    }
    // printf("check == %d, size - 1 == %d\n", check, size - 1);
    if (check == size - 1)
    {
        ft_error_msg("is already sorted");
    }
}

void    check_is_overlap(int *nums, int size)
{
    int i;
    int j;
    
    j = 0;
    i = 0;
    while (i < size)
    {
        j = i;
        while (j < size)
        {
            if (nums[i] == nums[j + 1])
                ft_error_msg("is overlaped");
            j++;
        }
        i++;
    }
} 

int *parsing(int ac, char **av, int *arr_size, int *nums)
{
    int size;
    (void)ac;
    check_is_int(av);
    *arr_size = get_array_size(av);
    size = *arr_size;
    nums = NULL;
    nums = get_num_array(av, size);
    check_is_sorted(nums, size);
    // check_is_overlap(nums, size);

    return nums;
    // printf("%d\n", nums[0]);
}