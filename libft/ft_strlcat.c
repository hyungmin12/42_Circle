/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:27:12 by hyyoo             #+#    #+#             */
/*   Updated: 2022/10/05 09:56:14 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>
int ft_strlen(const char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return i;
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

int main()
{
	char s1[30] = "this test is";
	char s2[30] = "made by jungyeki";
	char s3[30] = "this test is";
	char s4[30] = "made by jungyeki";

	printf("%zu    %lu\n", ft_strlcat(s1, s2, 0), strlcat(s1, s2, 0));
	printf("%zu    %lu\n", ft_strlcat(s3, s4, 29), strlcat(s3, s4, 29));

}
