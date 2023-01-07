/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:24:51 by hyyoo             #+#    #+#             */
/*   Updated: 2022/08/08 17:40:41 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s1)
{
	char		*cpy;
	int			i;
	int			len;

	cpy = NULL;
	i = 0;
	len = ft_strlen(s1);
	if (s1[len - 1] == '\n')
		len -= 1;
	cpy = (char *)ft_calloc(len + 1, sizeof(char));
	if (!cpy)
		return (NULL);
	while (i < len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
