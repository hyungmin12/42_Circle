/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:53:39 by hyyoo             #+#    #+#             */
/*   Updated: 2023/06/29 21:02:23 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

# define K_AR_L 123
# define K_AR_R 124
# define K_A 0
# define K_S 1
# define K_D 2
# define K_W 13
# define K_ESC 53
# define TEX_W 64
# define TEX_H 64
# define MAP_W 24
# define MAP_H 24
# define WIDTH 640
# define HEIGHT 480
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

typedef struct s_cam
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perwalldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		lineheight;
	int		wallstart;
	int		wallend;
	int		texnum;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
}	t_cam;

typedef struct s_elem
{
	char	*ea_path;
	char	*we_path;
	char	*so_path;
	char	*no_path;
	int		floor_col[3];
	int		ceil_col[3];
}	t_elem;

typedef struct s_map
{
	char	**map;
	char	start_dir;
}	t_map;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		l_size;
	int		bpp;
	int		endian;
	int		img_w;
	int		img_h;
}	t_img;

typedef struct s_info
{
	t_elem		element;
	t_map		map;
	t_img		img;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	void		*mlx;
	void		*win;
	int			buf[HEIGHT][WIDTH];
	int			tex[4][64][64];
	double		move_s;
	double		rot_s;
}	t_info;

int		ft_loop(t_info *info);
int		key_press(int key, t_info *info);
int		ft_redbutton(int key_code, void *data);
void	ft_set_cam(t_info *info, t_cam *cam, int x);
void	ft_draw_cam(t_info *info, t_cam *cam, int x);
void	ft_load_tex(t_info *info);
void	ft_get_elem(int fd, t_info *info);
void	ft_get_and_check_map(int fd, t_info *info);
void	ft_get_file_and_path(char *map_path, t_info *info);
void	ft_error(void);
void	ft_init(char dir, t_info *info);
void	parse_rgb(char *str, int *color_store);
void	ft_ch_str_cnt(char **p_str, int count);
void	ft_get_tex_path(t_elem *e, char *str, int *flag);
void	check_world_map(char **map);

#endif
