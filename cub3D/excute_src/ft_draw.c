/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:08:46 by hyyoo             #+#    #+#             */
/*   Updated: 2023/06/29 20:53:10 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_draw_tex(t_info *info, t_cam *cam, int x)
{
	int	color;

	if (cam->side == 0)
		cam->wall_x = info->pos_y + cam->perwalldist * cam->raydir_y;
	else
		cam->wall_x = info->pos_x + cam->perwalldist * cam->raydir_x;
	cam->wall_x -= floor(cam->wall_x);
	cam->tex_x = (int)(cam->wall_x * (double)TEX_W);
	if (cam->side == 0 && cam->raydir_x > 0)
		cam->tex_x = TEX_W - cam->tex_x - 1;
	if (cam->side == 1 && cam->raydir_y < 0)
		cam->tex_x = TEX_W - cam->tex_x - 1;
	cam->step = 1.0 * TEX_H / cam->lineheight;
	cam->tex_pos = (cam->wallstart - HEIGHT
			/ 2 + cam->lineheight / 2) * cam->step;
	while (cam->wallstart < cam->wallend)
	{
		cam->tex_y = (int)cam->tex_pos & (TEX_H - 1);
		cam->tex_pos += cam->step;
		color = info->tex[cam->texnum][cam->tex_y][cam->tex_x];
		info->buf[cam->wallstart][x] = color;
		cam->wallstart++;
	}
}

static void	sel_tex(t_cam *cam)
{
	cam->texnum = 0;
	if (cam->side == 0)
	{
		if (cam->raydir_x < 0)
			cam->texnum = 2;
		else
			cam->texnum = 3;
	}
	else
	{
		if (cam->raydir_y < 0)
			cam->texnum = 0;
		else
			cam->texnum = 1;
	}
}

static void	set_wallpos(t_cam *cam)
{
	cam->lineheight = (int)(HEIGHT / cam->perwalldist);
	cam->wallstart = -cam->lineheight / 2 + HEIGHT / 2;
	if (cam->wallstart < 0)
		cam->wallstart = 0;
	cam->wallend = cam->lineheight / 2 + HEIGHT / 2;
	if (cam->wallend >= HEIGHT)
		cam->wallend = HEIGHT - 1;
}

void	ft_draw_cam(t_info *info, t_cam *cam, int x)
{
	set_wallpos(cam);
	sel_tex(cam);
	ft_draw_tex(info, cam, x);
}
