/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:40:29 by hyyoo             #+#    #+#             */
/*   Updated: 2022/06/04 23:39:13 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_nbr_size(long long nbr, int base_len);
int	ft_check_valide(char *base, int *len);
int	ft_is_space(char c);

int	atoi_base(char *str, char *base, int base_len)
{
	int	ret;
	int	sign;
	int	idx;

	ret = 0;
	sign = 1;
	while (ft_is_space(*str))
		++str;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (*str)
	{
		idx = -1;
		while (++idx < base_len)
		{
			if (*str == base[idx])
				break ;
		}
		if (idx == base_len)
			break ;
		ret = ret * base_len + idx;
		++str;
	}
	return (ret * sign);
}

char	*ft_putnbr_base(int nbr, char *base, int base_len)
{
	long long	tmp;
	char		*ret;
	int			size;

	tmp = nbr;
	size = ft_nbr_size(tmp, base_len);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!(ret))
		return (NULL);
	ret[size] = '\0';
	if (nbr == 0)
	{
		ret[0] = base[0];
		return (ret);
	}
	if (tmp < 0)
		tmp *= -1;
	while (tmp)
	{
		ret[--size] = base[tmp % base_len];
		tmp /= base_len;
	}
	if (nbr < 0)
		ret[0] = '-';
	return (ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	len_from;
	int	len_to;

	if (!ft_check_valide(base_from, &len_from)
		|| !ft_check_valide(base_to, &len_to))
		return (0);
	return (ft_putnbr_base(atoi_base(nbr, base_from, len_from),
			base_to, len_to));
}
