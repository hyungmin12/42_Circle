/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:28:52 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/12 14:07:53 by yuhyeongmin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1. 인자 중복 검사
// 2. 정수인지
// 3. 정수 범위인지
// 3. 띄어쓰기 포함인지

#include "push_swap.h"

int ft_is_space(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i++] == ' ')
        return (1);
    }
    return (0);
}

int *ft_atoi_and_rt(char **av, int *num_array, int num_array_size)
{
    int i;
    int k;

    i = 1;
    k = 0;
    (void)num_array_size;
    while (av[i])
    {
        if (ft_strlen(av[i]) == 1 && ft_is_space(av[i]) == 0)
            num_array[k++] = ft_atoi(av[i++]);
    }

    return (num_array);
}
// ./pusg 2  3 4 5 53 2 " 12  11 3"

// void parcing(int ac, char **av)
// {
//     check_array(ac, av);
// }