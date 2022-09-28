/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 00:52:01 by hyyoo             #+#    #+#             */
/*   Updated: 2022/06/04 21:29:21 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct s_info
{
	char		seq[11];
	int			row[10];
	int			diag1[19];
	int			diag2[19];
	int			count;
}		t_info;

void	set_chk_var(int col, int row, int var, t_info *info)
{
	(info->row)[col] = var;
	(info->diag1)[row - col + 9] = var;
	(info->diag2)[col + row] = var;
}

void	recursive(t_info *info, int row)
{
	int	col;

	if (row == 10)
	{
		write(1, info->seq, 11);
		++(info->count);
	}
	col = 0;
	while (col < 10)
	{
		if (!(info->row)[col] && !(info->diag1)[row - col + 9]
				&& !(info->diag2)[col + row])
		{
			set_chk_var(col, row, 1, info);
			(info->seq)[row] = '0' + col;
			recursive(info, row + 1);
			set_chk_var(col, row, 0, info);
		}
		col++;
	}
}

void	init(t_info	*info)
{
	int	i;

	(info->seq)[10] = '\n';
	info->count = 0;
	i = 0;
	while (i < 10)
	{
		(info->row)[i] = 0;
		(info->diag1)[i] = 0;
		(info->diag2)[i] = 0;
		i++;
	}
	while (i < 19)
	{
		(info->diag1)[i] = 0;
		(info->diag2)[i] = 0;
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	t_info	info;

	init(&info);
	recursive(&info, 0);
	return (info.count);
}
