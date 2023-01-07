/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:30:08 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/07 11:43:01 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_to_floor(t_game *game, int x_move, int y_move)
{
	char	tmp;

	tmp = '\0';
	printf("move cnt = %d\n", ++game->player_move_cnt);
	tmp = game->str_line[game->player_y][game->player_x];
	game->str_line[game->player_y][game->player_x]
		= game->str_line[game->player_y + y_move][game->player_x + x_move];
	game->str_line[game->player_y + y_move][game->player_x + x_move] = tmp;
	game->player_y += y_move;
	game->player_x += x_move;
}

void	move_key_w(t_game *game)
{
	char	move;

	move = game->str_line[game->player_y - 1][game->player_x];
	if (move == '0')
		move_to_floor(game, 0, -1);
	else if (move == 'C')
	{
		printf("move cnt = %d\n", ++game->player_move_cnt);
		game->collec--;
		game->str_line[game->player_y - 1][game->player_x] = 'P';
		game->str_line[game->player_y][game->player_x] = '0';
		game->player_y -= 1;
	}
	else if (move == 'E' && game->collec == 0)
	{
		printf("move cnt = %d\n", ++game->player_move_cnt);
		get_free_and_exit(NULL, game);
	}
}

void	move_key_s(t_game *game)
{
	char	move;

	move = game->str_line[game->player_y +1][game->player_x];
	if (move == '0')
		move_to_floor(game, 0, +1);
	else if (move == 'C')
	{
		printf("move cnt = %d\n", ++game->player_move_cnt);
		game->collec--;
		game->str_line[game->player_y + 1][game->player_x] = 'P';
		game->str_line[game->player_y][game->player_x] = '0';
		game->player_y += 1;
	}
	else if (move == 'E' && game->collec == 0)
	{
		printf("move cnt = %d\n", ++game->player_move_cnt);
		get_free_and_exit(NULL, game);
	}
}

void	move_key_a(t_game *game)
{
	char	move;

	move = game->str_line[game->player_y][game->player_x - 1];
	if (move == '0')
		move_to_floor(game, -1, 0);
	else if (move == 'C')
	{
		printf("move cnt = %d\n", ++game->player_move_cnt);
		game->collec--;
		game->str_line[game->player_y][game->player_x - 1] = 'P';
		game->str_line[game->player_y][game->player_x] = '0';
		game->player_x -= 1;
	}
	else if (move == 'E' && game->collec == 0)
	{
		printf("move cnt = %d\n", ++game->player_move_cnt);
		get_free_and_exit(NULL, game);
	}
}

void	move_key_d(t_game *game)
{
	char	move;

	move = game->str_line[game->player_y][game->player_x + 1];
	if (move == '0')
		move_to_floor(game, +1, 0);
	else if (move == 'C')
	{
		printf("move cnt = %d\n", ++game->player_move_cnt);
		game->collec--;
		game->str_line[game->player_y][game->player_x + 1] = 'P';
		game->str_line[game->player_y][game->player_x] = '0';
		game->player_x += 1;
	}
	else if (move == 'E' && game->collec == 0)
	{
		printf("move cnt = %d\n", ++game->player_move_cnt);
		get_free_and_exit(NULL, game);
	}
}
