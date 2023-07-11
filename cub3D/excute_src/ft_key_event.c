/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:08:58 by hyyoo             #+#    #+#             */
/*   Updated: 2023/06/29 20:42:32 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_key_lr(int key, t_info *info, double olddir_x, double oldplane_x)
{
	if (key == K_AR_R)
	{
		info->dir_x = info->dir_x * cos(-info->rot_s)
			- info->dir_y * sin(-info->rot_s);
		info->dir_y = olddir_x * sin(-info->rot_s)
			+ info->dir_y * cos(-info->rot_s);
		info->plane_x = info->plane_x * cos(-info->rot_s)
			- info->plane_y * sin(-info->rot_s);
		info->plane_y = oldplane_x * sin(-info->rot_s)
			+ info->plane_y * cos(-info->rot_s);
	}
	else if (key == K_AR_L)
	{
		info->dir_x = info->dir_x * cos(info->rot_s)
			- info->dir_y * sin(info->rot_s);
		info->dir_y = olddir_x * sin(info->rot_s)
			+ info->dir_y * cos(info->rot_s);
		info->plane_x = info->plane_x * cos(info->rot_s)
			- info->plane_y * sin(info->rot_s);
		info->plane_y = oldplane_x * sin(info->rot_s)
			+ info->plane_y * cos(info->rot_s);
	}
}

static void	ft_key_ad(int key, t_info *info)
{
	if (key == K_A)
	{
		if (info->map.map[(int)(info->pos_x - info->plane_x * info->move_s)]
				[(int)(info->pos_y)] != '1')
			info->pos_x -= info->plane_x * info->move_s;
		if (info->map.map[(int)(info->pos_x)]
				[(int)(info->pos_y - info->plane_y * info->move_s)] != '1')
			info->pos_y -= info->plane_y * info->move_s;
	}
	else if (key == K_D)
	{
		if (info->map.map[(int)(info->pos_x + info->plane_x * info->move_s)]
				[(int)(info->pos_y)] != '1')
			info->pos_x += info->plane_x * info->move_s;
		if (info->map.map[(int)(info->pos_x)]
				[(int)(info->pos_y + info->plane_y * info->move_s)] != '1')
			info->pos_y += info->plane_y * info->move_s;
	}
}

static void	ft_key_ws(int key, t_info *info)
{
	if (key == K_W)
	{
		if (info->map.map[(int)(info->pos_x + info->dir_x * info->move_s)]
				[(int)(info->pos_y)] != '1')
			info->pos_x += info->dir_x * info->move_s;
		if (info->map.map[(int)(info->pos_x)]
				[(int)(info->pos_y + info->dir_y * info->move_s)] != '1')
			info->pos_y += info->dir_y * info->move_s;
	}
	else if (key == K_S)
	{
		if (info->map.map[(int)(info->pos_x - info->dir_x * info->move_s)]
				[(int)(info->pos_y)] != '1')
			info->pos_x -= info->dir_x * info->move_s;
		if (info->map.map[(int)(info->pos_x)]
				[(int)(info->pos_y - info->dir_y * info->move_s)] != '1')
			info->pos_y -= info->dir_y * info->move_s;
	}
}

int	key_press(int key, t_info *info)
{
	if (key == K_W || key == K_S)
		ft_key_ws(key, info);
	else if (key == K_A || key == K_D)
		ft_key_ad(key, info);
	else if (key == K_AR_L || key == K_AR_R)
		ft_key_lr(key, info, info->dir_x, info->plane_x);
	else if (key == K_ESC)
		exit(0);
	return (0);
}

int	ft_redbutton(int key_code, void *data)
{
	(void)key_code;
	data = NULL;
	exit(0);
}
