/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:31:01 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/07 11:35:56 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_error_msg(char *error_msg)
{
	write(2, "Error\n", 6);
	write(2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
	exit(1);
}

void	free_table(char **table)
{
	int	i;

	i = 0;
	while (table[i])
		free(table[i++]);
	free(table);
}

void	get_free_and_exit(char *error_msg, t_game *game)
{
	if (error_msg)
	{
		write(2, "Error\n", 6);
		write(2, error_msg, ft_strlen(error_msg));
		write(2, "\n", 1);
	}
	free_table(game->str_line);
	if (error_msg)
		exit(1);
	else
		exit(0);
}
