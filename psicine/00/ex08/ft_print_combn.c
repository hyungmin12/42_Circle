/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 00:52:41 by hyyoo             #+#    #+#             */
/*   Updated: 2022/05/29 03:05:06 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	recursive(int i, int nbr, int len, char *buf)
{
	if (nbr == len)
	{
		write(1, buf, len);
		write(1, ", ", 2);
		return ;
	}
	while (++i <= 10 - (len - nbr))
	{
		buf[nbr] = '0' + i;
		recursive(i, nbr + 1, len, buf);
	}
}

void	ft_print_last(int i)
{
	char	c;

	while (i <= 9)
	{
		c = '0' + i++;
		write(1, &c, 1);
	}
}

void	ft_print_combn(int nbr)
{
	int		i;
	char	buf[10];
	int		len;

	if (!(nbr > 0 && nbr < 10))
		return ;
	i = 0;
	len = nbr;
	while (i < 10 - nbr)
	{
		buf[0] = '0' + i;
		recursive(i, 1, len, buf);
		i++;
	}
	ft_print_last(i);
}
