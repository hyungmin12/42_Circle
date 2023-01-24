/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:04:08 by youjeon           #+#    #+#             */
/*   Updated: 2023/01/24 19:30:20 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	set_a_location(int num, t_info *info)
{
	int	ret;

	if (num < get_stack_min(info->top_a))
		ret = set_a_location_min(info);
	else if (num > get_stack_max(info->top_a))
		ret = set_a_location_max(info);
	else
		ret = set_a_location_mid(num, info);
	return (ret);
}

void	ft_rotate_same(t_info *info, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		ft_rr(info);
		*a = *a - 1;
		*b = *b - 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		ft_rrr(info);
		*a = *a + 1;
		*b = *b + 1;
	}
}

void	ft_rotate_a(t_info *info, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ft_ra(info);
			a--;
		}
		else
		{
			ft_rra(info);
			a++;
		}
	}
}

void	ft_rotate_b(t_info *info, int b)
{
	while (b)
	{
		if (b > 0)
		{
			ft_rb(info);
			b--;
		}
		else
		{
			ft_rrb(info);
			b++;
		}
	}
}
