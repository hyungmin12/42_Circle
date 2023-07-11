/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:09:16 by hyyoo             #+#    #+#             */
/*   Updated: 2023/06/29 21:02:34 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_floor_and_ceil(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 480)
	{
		j = -1;
		while (++j < 640)
		{
			if (i < 240)
			{
				info->buf[i][j] = info->element.floor_col[0] << 16;
				info->buf[i][j] += info->element.floor_col[1] << 8;
				info->buf[i][j] += info->element.floor_col[2];
			}
			else
			{
				info->buf[i][j] = info->element.ceil_col[0] << 16;
				info->buf[i][j] += info->element.ceil_col[1] << 8;
				info->buf[i][j] += info->element.ceil_col[2];
			}
		}
	}
}

static void	ft_draw(t_info *info)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			info->img.data[y * WIDTH + x] = info->buf[y][x];
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

static void	ft_raycasting(t_info *info)
{
	int			x;
	t_cam		cam;

	x = -1;
	ft_floor_and_ceil(info);
	while (++x < WIDTH)
	{
		ft_set_cam(info, &cam, x);
		ft_draw_cam(info, &cam, x);
	}
}

int	ft_loop(t_info *info)
{
	ft_raycasting(info);
	ft_draw(info);
	return (0);
}
