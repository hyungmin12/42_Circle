/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:09:21 by hyyoo             #+#    #+#             */
/*   Updated: 2023/06/29 20:53:10 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	find_wall(t_info *info, t_cam *cam)
{
	while (cam->hit == 0)
	{
		if (cam->sidedist_x < cam->sidedist_y)
		{
			cam->sidedist_x += cam->deltadist_x;
			cam->map_x += cam->step_x;
			cam->side = 0;
		}
		else
		{
			cam->sidedist_y += cam->deltadist_y;
			cam->map_y += cam->step_y;
			cam->side = 1;
		}
		if (info->map.map[cam->map_x][cam->map_y] == '1')
			cam->hit = 1;
	}
}

static void	set_dir(t_info *info, t_cam *cam)
{
	if (cam->raydir_x < 0)
	{
		cam->step_x = -1;
		cam->sidedist_x = (info->pos_x - cam->map_x) * cam->deltadist_x;
	}
	else
	{
		cam->step_x = 1;
		cam->sidedist_x = (cam->map_x + 1.0 - info->pos_x) * cam->deltadist_x;
	}
	if (cam->raydir_y < 0)
	{
		cam->step_y = -1;
		cam->sidedist_y = (info->pos_y - cam->map_y) * cam->deltadist_y;
	}
	else
	{
		cam->step_y = 1;
		cam->sidedist_y = (cam->map_y + 1.0 - info->pos_y) * cam->deltadist_y;
	}
}

void	ft_set_cam(t_info *info, t_cam *cam, int x)
{
	cam->camera_x = 2 * x / (double)WIDTH - 1;
	cam->raydir_x = info->dir_x + info->plane_x * cam->camera_x;
	cam->raydir_y = info->dir_y + info->plane_y * cam->camera_x;
	cam->map_x = (int)info->pos_x;
	cam->map_y = (int)info->pos_y;
	cam->deltadist_x = fabs(1 / cam->raydir_x);
	cam->deltadist_y = fabs(1 / cam->raydir_y);
	cam->hit = 0;
	set_dir(info, cam);
	find_wall(info, cam);
	if (cam->side == 0)
		cam->perwalldist = (cam->map_x - info->pos_x
				+ (1 - cam->step_x) / 2) / cam->raydir_x;
	else
		cam->perwalldist = (cam->map_y - info->pos_y
				+ (1 - cam->step_y) / 2) / cam->raydir_y;
}
