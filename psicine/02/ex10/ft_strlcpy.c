/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:06:14 by hyyoo             #+#    #+#             */
/*   Updated: 2022/05/24 16:59:54 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	ret;

	i = 0;
	ret = 0;
	while (src[ret])
		ret++;
	if (size < 1)
		return (ret);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ret);
}
/*
int main(void)
{
	char c[10] = "asdfg";
	char b[20] = "123455667";

	ft_strlcpy(c, b, 3);
	int i = 0;
	
	
	printf("%u", ft_strlcpy(c, b, 7));
	
}*/
//  복사 해주고 복사한 길이열 출력. src[ret]출력
//  
//  size < 1  size 가 0이라면 아이에 끝내버려야 하는데 만약 이 조건이 없다면 내려가서 데스트에 널값을 넣는 조작을 한다.
