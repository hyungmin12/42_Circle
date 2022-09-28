/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:36:26 by hyyoo             #+#    #+#             */
/*   Updated: 2022/05/30 02:01:19 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_num(int nbr, int len, char *base)
{
	if (!nbr)
		return ;
	ft_print_num(nbr / len, len, base);
	write(1, &base[nbr % len], 1);
}

int	ft_get_len(int *len, char *base)
{
	int	chk[256];
	int	i;

	i = 0;
	while (i < 256)
		chk[i++] = 0;
	*len = 0;
	while (base[*len])
	{
		if (chk[(int)base[*len]] == 1 || base[*len] == '+' || base[*len] == '-')
			return (0);
		chk[(int)base[(*len)]] = 1;
		(*len)++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	tmp;
	int			len;

	if (!ft_get_len(&len, base) || len == 0 || len == 1)
		return ;
	tmp = nbr;
	if (tmp < 0)
	{
		tmp *= -1;
		write(1, "-", 1);
	}
	ft_print_num(tmp / len, len, base);
	write(1, &base[tmp % len], 1);
}
