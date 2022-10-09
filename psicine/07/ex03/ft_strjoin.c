/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:35:45 by hyyoo             #+#    #+#             */
/*   Updated: 2022/10/09 16:33:28 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *s1, char *s2)
{
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	return (s1);
}

int	strlen_char(char **str, char *sep, int size)
{
	int	result;
	int	i;
	int	j;

	i = 0;
	result = 0;
	while (str[i] && i < size)
	{
		j = 0;
		while (str[i][j])
		{
			result++;
			j++;
		}
		i++;
	}
	i = 0;
	result += (size - 1) * ft_strlen(sep);
	return (result + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int			i;
	char		*ret;
	char		*result;

	if (size == 0)
	{
		ret = (char *)malloc(sizeof(char) * 1);
		ret[0] = 0;
		return (ret);
	}
	ret = (char *)malloc(sizeof(char) * (strlen_char(strs, sep, size)));
	i = 0;
	result = ret;
	while (strs[i] && i < size)
	{
		ret = ft_strcpy(ret, strs[i]);
		if (i != size - 1)
			ret = ft_strcpy(ret, sep);
		i++;
	}
	*ret = 0;
	return (result);
}

#include<stdio.h>
int	main(void)
{
	char	*tab[4];
	tab[0] = "1";
	tab[1] = "2";
	tab[2] = "3";
	tab[3] = "4";
	printf("%s", ft_strjoin(4, tab, "Pasquale"));
	return (0);
}
