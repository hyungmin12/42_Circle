/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:59:56 by hyyoo             #+#    #+#             */
/*   Updated: 2022/07/31 19:08:17 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*hay;
	char			*need;

	i = 0;
	j = 0;
	hay = (char *)haystack;
	need = (char *)needle;
	if (!need[i])
		return (hay);
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (hay[i + j] == need[j] && (i + j) < len)
		{
			if (!need[j + 1])
				return (&hay[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
