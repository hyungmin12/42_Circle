/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 03:25:36 by hyyoo             #+#    #+#             */
/*   Updated: 2022/06/05 04:09:23 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	show_size(int size)
{
	char	ch;

	if (size == 0)
		return ;
	ch = '0' + size % 10;
	show_size(size / 10);
	write(1, &ch, 1);
}

void	ft_show_tab(struct s_stock_str *stock)
{
	int	idx;

	idx = 0;
	while (stock[idx].str)
	{
		write(1, stock[idx].str, stock[idx].size);
		write(1, "\n", 1);
		if (stock[idx].size != 0)
			show_size(stock[idx].size);
		else
			write(1, "0", 1);
		write(1, "\n", 1);
		write(1, stock[idx].copy, stock[idx].size);
		write(1, "\n", 1);
		++idx;
	}
}
