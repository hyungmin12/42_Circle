/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:19:32 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/27 23:08:41 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	b_from_a(t_info *info)
// {
// 	int	max;
// 	int	mid;
// 	int	max_index;

// 	max = info->size_b;
// 	while (max > 0)
// 	{
// 		max_index = get_index(info, info->size_b, 2);
// 		mid = max / 2;
// 		if (max_index <= mid)
// 			while ((max_index--) > 0)
//                 ft_rb(info);
// 		else
// 			while ((max_index++) < max)
//                 ft_rrb(info);
//         ft_pa(info);
// 		max--;
// 	}
// }

// void	ft_sort_more_than_five(t_info *info)
// {
// 	int	index;
// 	int	chunk;

// 	// chunk = 0.000000053 * info->size_a * info->size_a + 0.03 * info->size_a + 14.5;
//     chunk = 15;
// 	index = 0;
//     if (info->size_a > 499)
//         chunk = 30;
// 	while (info->size_a > 0)
// 	{
// 		if (info->top_a->content <= index)
// 		{
//             ft_pb(info);
// 			index++;
// 		}
// 		else if (info->top_a->content <= index + chunk)
// 		{
// 			ft_pb(info);
// 			ft_rb(info);
// 			index++;
// 		}
// 		else
// 			ft_ra(info);
// 	}
// 	b_from_a(info);
// }