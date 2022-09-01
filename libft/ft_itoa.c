/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:36:36 by hyyoo             #+#    #+#             */
/*   Updated: 2022/08/13 17:22:28 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len(int n)
{
	int	i;

	if (n < 0)
		i = 1;
	else
		i = 0;
	if (n < 0)
		n = n * -1;
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_sign(int *n, int *sign)
{
	if (*n < 0)
		*sign = 1;
	else
		*sign = 0;
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		sign;

	ft_sign(&n, &sign);
	i = len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(i + 1);
	if (!(str))
		return (NULL);
	if (n < 0)
		n = n * -1;
	str[i] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
