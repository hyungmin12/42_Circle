/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:16:11 by hyyoo             #+#    #+#             */
/*   Updated: 2022/07/31 17:15:26 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char			*dst_tmp;
	char			*src_tmp;
	unsigned int	i;

	dst_tmp = (char *)dst;
	src_tmp = (char *)src;
	i = 0;
	if (n == 0 || dst == src)
		return (dst_tmp);
	while (i < n)
	{
		dst_tmp[i] = src_tmp[i];
		i++;
	}
	return (dst_tmp);
}
