/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:52:19 by hyyoo             #+#    #+#             */
/*   Updated: 2022/06/04 16:18:23 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	i = 0;
	if (min >= max)
		return (0);
	size = max - min;
	range[0] = (int *)malloc(sizeof(int) * size);
	if (!range[0])
		return (-1);
	while (i < size)
	{
		range[0][i++] = min++;
	}
	return (size);
}
