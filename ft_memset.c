/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:01:55 by hyyoo             #+#    #+#             */
/*   Updated: 2022/07/18 15:01:18 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int c, size_t len)
{
	unsigned int	i;
	char			*mem;

	i = 0;
	mem = (char *)p;
	while (i < len)
	{
		mem[i] = (unsigned char)c;
		i++;
	}
	return ((void *)mem);
}
