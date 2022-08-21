/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:26:27 by hyyoo             #+#    #+#             */
/*   Updated: 2022/07/15 16:34:15 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_check_set(char const *s1, char c)
{
	int		i;
	char	*set;

	i = 0;
	set = (char *)s1;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (*s1 == 0)
		return (ft_strdup((char *)s1));
	if (*set == 0)
		return (ft_strdup(s1));
	while (s1[i] != '\0' && ft_check_set(set, s1[i]) == 1)
		i++;
	while (ft_check_set(set, s1[j]) == 1 && j > i)
		j--;
	return (ft_substr(s1, i, j - i + 1));
}
