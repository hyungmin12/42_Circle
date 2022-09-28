/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:11:50 by hyyoo             #+#    #+#             */
/*   Updated: 2022/05/22 13:53:25 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int main(void)
{
	char dest[10] = "1234";
	char src[10] = "asdfghj";
	
	int i;
	i = 0;

	ft_strcpy(dest, src);
	
	while(i < 10)
		printf("%c",src[i++]);

	return 0;
}
*/
