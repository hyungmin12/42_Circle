/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:53:52 by hyyoo             #+#    #+#             */
/*   Updated: 2022/08/13 18:29:28 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*cpy;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;	
	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
	{
		cpy = malloc(1);
		if (!cpy)
			return (NULL);
		cpy[0] = '\0';
		return (cpy);
	}
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	while (s[i] && 0 < len)
	{
		cpy[j++] = s[start++];
		len--;
		i++;
	}
	cpy[j] = '\0';
	return (cpy);
}*/

size_t	ft_len(char const *src, unsigned int idx, size_t len)
{
	size_t	size;
	size_t	start;
	start = idx;
	size = ft_strlen(src) - idx + 1;
	if (size < len)
		return (size);
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	length;
	char	*cpy;

	i = 0;
	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
	{
		cpy = malloc(1);
		if (!cpy)
			return (NULL);
		cpy[0] = '\0';
		return (cpy);
	}
	length = ft_len(s, start, len);
	cpy = (char *)malloc(sizeof(char) * (length + 1));
	if (!cpy)
		return (NULL);
	while (i < length)
		cpy[i++] = s[start++];
	cpy[i] = '\0';
	return (cpy);
}
