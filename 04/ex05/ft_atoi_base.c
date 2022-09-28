/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 02:42:19 by hyyoo             #+#    #+#             */
/*   Updated: 2022/05/30 02:03:59 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_chk_lens(int *len, char *base)
{
	int	chk[256];
	int	i;

	i = 0;
	while (i < 256)
		chk[i++] = 0;
	*len = 0;
	while (base[*len])
	{
		if (chk[(int)base[*len]]
			|| ('\t' <= base[*len] && base[*len] <= '\r')
			|| base[*len] == ' ' || base[*len] == '+'
			|| base[*len] == '-')
			return (0);
		chk[(int)base[*len]] = 1;
		(*len)++;
	}
	return (1);
}

int	ft_idx(char c, int len, char *base)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	res;
	int	idx;
	int	len;

	sign = 1;
	res = 0;
	if (!ft_chk_lens(&len, base) || len == 0 || len == 1)
		return (0);
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*(str++) == '-')
			sign *= -1;
	}
	while (*str)
	{
		idx = ft_idx(*str, len, base);
		if (idx == -1)
			break ;
		res = res * len + idx;
		str++;
	}
	return (res * sign);
}
