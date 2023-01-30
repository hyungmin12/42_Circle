/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:06:50 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/30 20:12:51 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_split_size(char **split_str)
{
    int i;

    i = 0;
    while (split_str[i])
        i++;
    return i;
}

int ft_str_space(char *str)
{
    int i = 0;
    while (str[i])
    {
        if(str[i] == ' ')
            return 1;
        i++;
    }
    return 0;
}

int get_array_size(char **av)
{
    int i = 0;
    char **split_str;
    int size = 0;
    while (av[i])
    {
        if (ft_str_space(av[i]))
        {
            split_str = ft_split(av[i], ' ');
            size+= get_split_size(split_str);
            free_str(split_str);
        }
        else
            size++;
        i++;
    }
    // printf("%d\n", size - 1);
    return size-1;
}


int *get_num_array(char **av, int size)
{
    int *nums;
    int ac_size;
    int j;
    int i;
    char **split_str;
    
    i = 1;
    j = 0;
    ac_size = 0;
    nums = (int *)malloc(sizeof(int) * size);

    while (av[i])
    {
        j = 0;
        split_str = ft_split(av[i], ' ');
        while (split_str[j])
        {
            nums[ac_size++] = ft_atoi(split_str[j++]);
        }
        free_str(split_str);
        i++;
    }
    return nums;
}


