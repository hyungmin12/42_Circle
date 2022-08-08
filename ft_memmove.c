/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:32:05 by hyyoo             #+#    #+#             */
/*   Updated: 2022/08/07 01:11:44 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmp_dst;
	unsigned char		*tmp_src;
	unsigned int		i;

	i = 0;
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (tmp_dst == NULL && tmp_src == NULL)
		return (NULL);
	if (tmp_dst < tmp_src)
	{
		while (i < len)
		{
			tmp_dst[i] = tmp_src[i];
			i++;
		}
	}
	else
	{
		while (0 < len--)
			tmp_dst[len] = tmp_src[len];
	}
	return (tmp_dst);
}
