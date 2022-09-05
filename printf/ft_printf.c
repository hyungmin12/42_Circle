/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 22:19:15 by hyyoo             #+#    #+#             */
/*   Updated: 2022/09/05 17:27:54 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	make_printf(const char c, va_list (*ap))
{
	int ret;

	ret = 0;
	if (c == 'c')
		ret += (ft_putchar((char)va_arg((*ap), int)));//노션에 이유 정리// gcc 컴파일러라 그럼.
	else if (c == 's')
		ret += (ft_putstr(va_arg((*ap), char *)));
	else if (c == 'd' || c == 'i')
		ret += (ft_putnbr(va_arg((*ap), int)));
	else if (c == 'u')
		ret += (ft_putnbr(va_arg((*ap), unsigned int)));
	else if (c == 'x' || c == 'X' || c == 'p')
		ret += (ft_puthex(va_arg((*ap), unsigned int), c));
	else if (c == '%')
	{
		write(1, "%%", 1);
		return (1);
	}
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int	i;
	int	count;

	va_start(ap, str);
	i = 0;
	count = 0;
	while(str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{	
			i++;// %의 다음 즉 c,s,d 등을 표현
			count = count + make_printf(str[i], &ap); // 현재 i는 c,s 등 여기서 가변인자 선언한 가변인자 ap를 make_print로 보냄
		}
		else
		{
			count = count + ft_putchar(str[i]);
		}
		i++;
	}
	va_end(ap);
	return (count);
}
/*
int main()
{
	
	char a[10] = "asdf";
	char s = 'a';
	int i = -2147483648;
	int j = -1234;

	int n = ft_printf("1 == %d, 2 == %s", i, "유형민");
	printf("\n");
	int m = ft_printf("3 == %d, 4 == %s", i, "유형민");
	printf("\n");
	ft_printf("n == %d", n);
	printf("\n");
	printf("n == %d", m);

	printf("\n");

	int k = printf("%d %d", i, j);
	printf("\n");
	int l = printf("%d %d", i, j);
	printf("\n");
	printf("n == %d", k);
	printf("\n");
	printf("m == %d", l);

	ft_printf("%c", '\0');
	printf("%c", '\0');
}*/
