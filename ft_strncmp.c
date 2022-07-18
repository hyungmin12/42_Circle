/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:48:14 by hyyoo             #+#    #+#             */
/*   Updated: 2022/07/18 15:17:05 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	unsigned int			i;
	unsigned int			j;

	i = 0;
	j = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while ((j < n) && str1[i] && str2[i])
	{
		if (str1[i] == str2[i])
		{
			i++;
		}
		else
			return (str1[i] - str2[i]);
	}
	return (0);
}
