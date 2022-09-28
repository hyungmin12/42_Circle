/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:48:19 by hyyoo             #+#    #+#             */
/*   Updated: 2022/06/04 23:03:50 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!tab)
		return (0);
	while (src[i])
	{
		tab[i] = src[j];
		i++;
		j++;
	}
	tab[i] = '\0';
	return (tab);
}
