/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:31:49 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/07 12:10:56 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_img	img_init(void *mlx)
{
	t_img		set;
	int		wid;
	int		hei;

	set.img_player = 
		mlx_xpm_file_to_image(mlx, "./src/img/player.xpm", &wid, &hei);
	set.img_exit =
		mlx_xpm_file_to_image(mlx, "./src/img/exit.xpm", &wid, &hei);
	set.img_floor =
		mlx_xpm_file_to_image(mlx, "./src/img/floor.xpm", &wid, &hei);
	set.img_wall =
		mlx_xpm_file_to_image(mlx, "./src/img/wall.xpm", &wid, &hei);
	set.img_collectible =
		mlx_xpm_file_to_image(mlx, "./src/img/collectible.xpm", &wid, &hei);
	return (set);
}

void	put_img(t_game *g, int i, int j)
{
	if (g->str_line[i][j] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->img.img_player, j * PIXEL, i * PIXEL);
	else if (g->str_line[i][j] == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->img.img_floor, j * PIXEL, i * PIXEL);
    	else if (g->str_line[i][j] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img.img_wall, j * PIXEL, i * PIXEL);
    	else if (g->str_line[i][j] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img.img_collectible, j * PIXEL, i * PIXEL);
    	else if (g->str_line[i][j] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img.img_exit, j * PIXEL, i * PIXEL);
}

int	set_img(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->num_row)
	{
		j = 0;
		while (j < game->num_col)
		{
			put_img(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
