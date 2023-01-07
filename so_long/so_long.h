/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:32:15 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/07 12:21:14 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define   SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include "./mlx/mlx.h"
# include "./src/gnl/get_next_line.h"

# define PIXEL                  63
# define X_EVENT_KEY_PRESS		2

# define X_EVENT_KEY_EXIT		17
# define KEY_ESC		        53
# define KEY_W			        13
# define KEY_A			        0
# define KEY_S			        1
# define KEY_D			        2

typedef struct s_img
{
	void	*img_player;
	void	*img_collectible;
	void	*img_wall;
	void	*img_exit;
	void	*img_floor;
}		t_img;

typedef struct s_game
{
	char	**str_line;
	int		num_row;
	int		num_col;
	int		collec;
	int		player;
	int		player_x;
	int		player_y;
	int		exit;
	int		player_move_cnt;
	void		*mlx;
	void		*win;
	t_img		img;

}		t_game;

void	ft_error_msg(char *error_msg);
void	parsing(char *map, t_game *game);
void	str_init(char *map, t_game *game);
void	get_free_and_exit(char *error_msg, t_game *game);
void	check_param_cnt(t_game *game);
void	check_requ(t_game *game);
void	check_wall(t_game *game);
void	put_img(t_game *g, int i, int j);
int	set_img(t_game *game);
void	move_key_W(t_game *game);
void	move_key_S(t_game *game);
void	move_key_A(t_game *game);
void	move_key_D(t_game *game);
void	print_map(char **line);
t_img	img_init(void *mlx);

#endif
