/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:27:12 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/07 12:25:12 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
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
