/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:52:19 by hyyoo             #+#    #+#             */
/*   Updated: 2022/10/09 17:20:04 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	if (min >= max)
		return (0);
	size = max - min;
	i = 0;
	range[0] = (int *)malloc(sizeof(int) * size);
	if (!range[0])
		return (-1);
	while (i < size)
	{
		range[0][i++] = min++;
	}
	return (size);
}
