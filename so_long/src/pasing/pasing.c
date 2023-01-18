/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:31:34 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/18 15:59:58 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_param_cnt(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->str_line[++i])
	{
		j = -1;
		while (game->str_line[i][++j])
		{
			if (game->str_line[i][j] == 'P')
			{
				game->player++;
				game->player_x = j;
				game->player_y = i;
			}
			else if (game->str_line[i][j] == 'E')
				game->exit++;
			else if (game->str_line[i][j] == 'C')
				game->collec++;
		}
	}
	if (!(game->player == 1 && game->exit == 1 && game->collec >= 1))
		get_free_and_exit("param cnt error", game);
}

void	check_requ(t_game *game)
{
	int	i;

	i = 0;
	game->num_col = (int)ft_strlen(game->str_line[0]);
	while (game->str_line[i])
	{
		if (game->num_col != (int)ft_strlen(game->str_line[i++]))
			get_free_and_exit("wall is not requ", game);
	}
}

void	check_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->str_line[i])
	{
		j = 0;
		while (game->str_line[i][j])
		{
			if ((i == 0 || i == game->num_row - 1)
				|| (j == 0 || j == game->num_col - 1))
			{
				if (game->str_line[i][j] != '1')
					get_free_and_exit("wall error", game);
			}
			j++;
		}
		i++;
	}
}

void	parsing(char *map, t_game *game)
{
	check_map_extention(map);
	str_init(map, game);
	check_param(game);
	check_param_cnt(game);
	check_requ(game);
	check_wall(game);
}
