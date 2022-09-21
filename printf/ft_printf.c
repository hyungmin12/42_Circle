/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 22:19:15 by hyyoo             #+#    #+#             */
/*   Updated: 2022/09/21 16:50:19 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_start(int *i, int *count)
{
	*i = -1;
	*count = 0;
}

int	ft_check_str(const char *str)
{
	if (!str)
		return (-1);
	return (0);
}

int	ft_check_len(int len)
{
	if (len == -1)
		return (-1);
	return (len);
}

static int	make_printf(const char c, va_list (*ap))
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret += (ft_putchar((char)va_arg((*ap), int)));
	else if (c == 's')
		ret += (ft_putstr(va_arg((*ap), char *)));
	else if (c == 'd' || c == 'i')
		ret += (ft_putnbr(va_arg((*ap), int)));
	else if (c == 'u')
		ret += (ft_putnbr(va_arg((*ap), unsigned int)));
	else if (c == 'p')
		ret += ft_putx(va_arg((*ap), unsigned long long));
	else if (c == 'x' || c == 'X')
		ret += (ft_puthex(va_arg((*ap), unsigned int), c));
	else if (c == '%')
		ret += (ft_putchar('%'));
	else
		ret = -1;
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	int		len;
	int		i;

	ft_check_str(str);
	va_start(ap, str);
	ft_start(&i, &count);
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{	
			len = make_printf(str[++i], &ap);
			count = count + len;
		}
		else
		{
			len = ft_putchar(str[i]);
			count = count + len;
		}
		ft_check_len(len);
	}
	va_end(ap);
	return (count);
}
