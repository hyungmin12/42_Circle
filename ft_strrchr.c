/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 00:32:03 by hyyoo             #+#    #+#             */
/*   Updated: 2022/07/14 16:52:26 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	chr;
	int		i;

	chr = c;
	i = ft_strlen(s);
	ptr = (char *)s;
	if (ptr[i] == chr)
		return (&ptr[i]);
	while (i)
	{
		if ((ptr[i - 1]) == chr)
			return (&ptr[i - 1]);
		i--;
	}
	return (NULL);
}
