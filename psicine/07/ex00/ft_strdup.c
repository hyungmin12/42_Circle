/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:48:19 by hyyoo             #+#    #+#             */
/*   Updated: 2022/10/09 17:17:37 by hyyoo            ###   ########.fr       */
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
	int	len;
	char	*res;

	i = 0;
	j = 0;
	len = ft_strlen(src);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (0);
	while (src[i])
	{
		res[i] = src[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}
#include<stdio.h>
int main()
{
	printf("%s", ft_strdup("asdf"));
}
