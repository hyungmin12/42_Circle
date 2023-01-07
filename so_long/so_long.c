/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:32:06 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/07 12:15:44 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	struct_init(t_game *game)
{
	game->str_line = NULL;
	game->num_col = 0;
	game->num_row = 0;
	game->collec = 0;
	game->player = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->player_move_cnt = 0;
	game->exit = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->img.img_player = NULL;
	game->img.img_exit = NULL;
	game->img.img_collectible = NULL;
	game->img.img_floor = NULL;
	game->img.img_wall = NULL;
}

int	key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		get_free_and_exit(NULL, game);
	else if (key == KEY_W)
		move_key_w(game);
	else if (key == KEY_S)
		move_key_s(game);
	else if (key == KEY_A)
		move_key_a(game);
	else if (key == KEY_D)
		move_key_d(game);
	return (0);
}

int	red_btn(t_game *game)
{
	get_free_and_exit(NULL, game);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		struct_init(&game);
		parsing(av[1], &game);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, game.num_col * PIXEL, game.num_row * PIXEL, "so_long");
		game.img = img_init(game.mlx);
		printf("move cnt = %d\n", game.player_move_cnt);
		mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
		mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &red_btn, &game);
		mlx_loop_hook(game.mlx, &set_img, &game);
		mlx_loop(game.mlx);
	}
	else
		ft_error_msg("argument is not 2");
	return (0);
}
