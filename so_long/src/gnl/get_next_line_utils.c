/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:15:15 by hyyoo             #+#    #+#             */
/*   Updated: 2022/09/16 17:19:07 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_len(char const *src, unsigned int idx, size_t len)
{
	size_t	size;

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

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len_s1;
	unsigned int	len_s2;
	unsigned int	i;
	char			*str;

	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc((sizeof(char) * len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[len_s1++] = s2[i++];
	}
	str[len_s1] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	find;
	int		i;

	find = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == find)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == find)
		return ((char *)s + i);
	return (0);
}
