/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:53:35 by hyyoo             #+#    #+#             */
/*   Updated: 2022/07/18 15:15:09 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p_s1;
	const unsigned char	*p_s2;

	p_s1 = (const unsigned char *)s1;
	p_s2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*p_s1 != *p_s2)
			return (*p_s1 - *p_s2);
		p_s1++;
		p_s2++;
	}
	return (0);
}
