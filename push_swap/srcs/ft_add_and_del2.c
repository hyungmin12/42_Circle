/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_and_del2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:05:35 by hyyoo             #+#    #+#             */
/*   Updated: 2023/02/09 16:36:26 by yuhyeongmin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_remove_back_a(t_info *info)
{
	t_num	*pri;
	t_num	*temp;

	pri = info->head_a;
	temp = pri->next;
	if (pri == NULL)
		return ;
	if (pri->next == NULL)
	{
		info->head_a = NULL;
		free(pri);
	}
	else
	{
		while (temp->next != NULL)
		{
			pri = temp;
			temp = temp->next;
		}
		pri->next = NULL;
		free(temp);
	}
	info->size_a--;
}

void	ft_remove_back_b(t_info *info)
{
	t_num	*pri;
	t_num	*temp;

	pri = info->head_b;
	temp = pri->next;
	if (pri == NULL)
		return ;
	if (pri->next == NULL)
	{
		info->head_b = NULL;
		free(pri);
	}
	else
	{
		while (temp->next != NULL)
		{
			pri = temp;
			temp = temp->next;
		}
		pri->next = NULL;
		free(temp);
	}
	info->size_b--;
}
