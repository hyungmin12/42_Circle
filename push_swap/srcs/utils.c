/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:24:21 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/30 22:04:23 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void stack_a(t_info *info)
{
	t_num *tmp;

	tmp = info->top_a;
	while (tmp)
	{
		printf("stack_a == %d\n", tmp->content);
		tmp = tmp->next;
	}
}

void stack_b(t_info *info)
{
	t_num *tmp;

	tmp = info->top_b;
	while (tmp)
	{
		printf("stack_b == %d\n", tmp->content);
		tmp = tmp->next;
	}
}

void ft_error_msg(char *msg)
{
    write(2, "Error\n", 6);
    write(2, msg, ft_strlen(msg));
    exit(1);
}

int ft_is_space(char c)
{
    if (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\v' || c == '\f')
        return (1);
    return (0);
}

void free_str(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

void check_is_digit(const char *str)
{
    int i = 1;

    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            ft_error_msg("av is not int");
        i++;
    }
}

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
        write(1, &str[i++], 1);
}