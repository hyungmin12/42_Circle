/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:47:59 by hyyoo             #+#    #+#             */
/*   Updated: 2022/05/23 15:39:03 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	len;
	int	tamp;

	i = 0;
	len = size - 1;
	while (i < len)
	{
		tamp = tab[i];
		tab[i] = tab[len];
		tab[len] = tamp;
		i++;
		len--;
	}
}
