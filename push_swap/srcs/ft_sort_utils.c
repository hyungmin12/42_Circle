/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:19:27 by hyyoo             #+#    #+#             */
/*   Updated: 2023/02/09 16:20:56 by yuhyeongmin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_bottom_a(t_info *info)
{
	t_num	*tmp;

	tmp = info->top_a;
	while (tmp != NULL)
	{
		info->bottom_a_content = tmp->content;
		tmp = tmp->next;
	}
}

int	get_index(t_info *info, int data)
{
	t_num	*tmp;
	int		index;

	index = 0;
	tmp = info->top_a;
	while (tmp != NULL)
	{
		if (tmp->content == data)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (-1);
}
