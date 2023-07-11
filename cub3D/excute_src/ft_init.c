/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:08:51 by hyyoo             #+#    #+#             */
/*   Updated: 2023/06/29 20:50:47 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_init_buf(t_info *info)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			info->buf[y][x] = 0;
	}
}

static void	ft_dir_we(char dir, t_info *info)
{
	if (dir == 'E')
	{
		info->plane_x = 0.66;
		info->plane_y = 0.0;
		info->dir_x = 0.0;
		info->dir_y = 1.0;
	}
	else if (dir == 'W')
	{
		info->plane_x = -0.66;
		info->plane_y = 0.0;
		info->dir_x = 0.0;
		info->dir_y = -1.0;
	}
}

static void	ft_dir_ns(char dir, t_info *info)
{
	if (dir == 'N')
	{
		info->plane_x = 0.0;
		info->plane_y = 0.66;
		info->dir_x = -1.0;
		info->dir_y = 0.0;
	}
	else if (dir == 'S')
	{
		info->plane_x = 0.0;
		info->plane_y = -0.66;
		info->dir_x = 1.0;
		info->dir_y = 0.0;
	}
}

void	ft_init(char dir, t_info *info)
{
	info->mlx = mlx_init();
	info->move_s = 0.15;
	info->rot_s = 0.1;
	if (dir == 'N' || dir == 'S')
		ft_dir_ns(dir, info);
	else if (dir == 'W' || dir == 'E')
		ft_dir_we(dir, info);
	ft_init_buf(info);
	ft_load_tex(info);
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "mlx");
	info->img.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp,
			&info->img.l_size, &info->img.endian);
}
