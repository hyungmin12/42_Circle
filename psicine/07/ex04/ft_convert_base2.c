/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:40:29 by hyyoo             #+#    #+#             */
/*   Updated: 2022/06/04 23:36:47 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space(char c)
{
	if (c == ' ' || ('\t' <= c && c <= '\r'))
		return (1);
	return (0);
}

int	ft_check_valide(char *base, int *len)
{
	int			check[256];
	int			i;
	char		c;

	i = 0;
	while (i < 256)
		check[i++] = 0;
	*len = 0;
	while (base[*len])
	{
		c = base[*len];
		if (check[(int)c] || c == '+' || c == '-' || ft_is_space(c))
			return (0);
		check[(int)c] = 1;
		(*len)++;
	}
	if (*len <= 1)
		return (0);
	return (1);
}

int	ft_nbr_size(long long nbr, int base_len)
{
	int	ret;

	if (nbr == 0)
		return (1);
	ret = 0;
	if (nbr < 0)
	{
		++ret;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= base_len;
		++ret;
	}
	return (ret);
}
