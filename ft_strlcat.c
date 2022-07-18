/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:27:12 by hyyoo             #+#    #+#             */
/*   Updated: 2022/07/18 15:16:54 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	dst_l;
	unsigned int	src_l;
	unsigned int	i;

	i = 0;
	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	if (dstsize < dst_l + 1)
		return (dstsize + src_l);
	while (src[i] && dst_l + 1 + i < dstsize)
	{
		dst[dst_l + i] = src[i];
		i++;
	}
	dst[dst_l + i] = '\0';
	return (dst_l + src_l);
}
