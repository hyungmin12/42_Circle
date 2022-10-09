/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:34:57 by hyyoo             #+#    #+#             */
/*   Updated: 2022/10/05 09:49:49 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (*dest && (i < size))
	{
		dest++;
		i++;
	}
	while (*src && ((i + 1) < size))
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	if (i < size)
	{
		*dest = 0;
	}
	while (*src)
	{
		i++;
		src++;
	}
	return (i);
}

int main()
{
	char s1[30] = "this test is";
	char s2[30] = "made by jungyeki";
	char s3[30] = "this test is";
	char s4[30] = "made by jungyeki";

	printf("%d    %lu\n", ft_strlcat(s1, s2, 0), strlcat(s1, s2, 0));
	printf("%d    %lu\n", ft_strlcat(s3, s4, 29), strlcat(s3, s4, 29));

}
