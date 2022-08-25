/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 22:19:15 by hyyoo             #+#    #+#             */
/*   Updated: 2022/08/25 16:35:30 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	make_printf(char c, va_list ap)
{
	int tmp;

	tmp = 0;
	if (c == 'c')
		return (ft_putchar((char)va_arg(ap, int)));//int로 표현되어 있음.. 이해 안감// 가변인자를 받아서 보냄.
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int), &tmp)); // int tmp = 0 을 선언해서 사용함. 왜?..
	/*if (c == 'u')
		return (ft_putunb(ap));
	if (c == 'c')
		return (ft_putchar((char)va_arg(ap, int)));
	if (c == 'c')
		return (ft_puthex(ap, c));
	if (c == '%')
	{
		write(1, "%%", 1);
		return (1);
	}*/
	return (0);
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
			i++; // %의 다음 즉 c,s,d 등을 표현
			count = count + make_printf(str[i], ap); // 현재 i는 c,s 등 여기서 가변인자 선언한 가변인자 ap를 make_print로 보냄
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

#include<stdio.h>

int main()
{
	int a = 42234;
	int s = 42452;

	int n = ft_printf("%d\n", a);
	int m = ft_printf("%d\n", s);
	ft_printf("n == %d\n", n);
	ft_printf("m == %d\n", m);
}
