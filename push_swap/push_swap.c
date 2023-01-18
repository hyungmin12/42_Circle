/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:23:14 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/12 14:10:20 by yuhyeongmin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1. 인자 중복 검사
// 2. 정수인지
// 3. 정수 범위인지
// 3. 띄어쓰기 포함인지

#include "push_swap.h"

int ft_error_msg(char *msg)
{
    write(2, "Error\n", 6);
    write(2, msg, ft_strlen(msg));
    exit(1);
}

 
int main(int ac, char **av)
{
    // int *num_array;
    // int num_array_size;

    // num_array = (int *)malloc(sizeof(int) * ac - 1);
    // num_array_size = ac - 1;
    
    // if (ac < 3)
    // {
    //     ft_error_msg("ac error");
    // }
    // // int i = 0;
    // num_array = ft_atoi_and_rt(av, num_array, num_array_size);
    // // while (i < 100)
    // // {
    // //     printf("%d", num_array[i++]);
    // // }
    int i = 1;
    while (i < ac) {
        // printf("%s\n", av[i++]);
        
    }
    return 0;
}