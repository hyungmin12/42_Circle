/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:36:36 by hyyoo             #+#    #+#             */
/*   Updated: 2022/07/15 17:40:31 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	len(long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		i;

	nb = n;
	i = len(nb);
	if (!(str = (char *)malloc(i + 1)))
		return(0);
	str[i] = '\0';
	i--;
	if (nb == 0)
	{
		str[0] = 48;
		return(str);
	}
	if(nb < 0)
	{
	str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[i] = '0' + (nb % 10);
		nb /= 10;
		i--;
	}
	return (str);
}
