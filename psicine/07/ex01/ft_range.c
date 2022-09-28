/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:53:29 by hyyoo             #+#    #+#             */
/*   Updated: 2022/06/02 21:14:47 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*tmp;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	size = max - min;
	tmp = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		tmp[i++] = min++;
	}
	return (tmp);
}
