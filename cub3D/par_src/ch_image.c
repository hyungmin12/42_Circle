/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:56:08 by hyyoo             #+#    #+#             */
/*   Updated: 2023/07/03 18:01:05 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_ch_dir(t_elem *e, char **elem_path, int *flag)
{
	if (!ft_strncmp(elem_path[0], "EA", 2)
		&& ft_strlen(elem_path[0]) == 2 && !flag[0])
	{
		e->ea_path = elem_path[1];
		flag[0] = 1;
		return (1);
	}
	else if (!ft_strncmp(elem_path[0], "WE", 2)
		&& ft_strlen(elem_path[0]) == 2 && !flag[1])
	{
		e->we_path = elem_path[1];
		flag[1] = 1;
		return (1);
	}
	return (0);
}

static int	ft_ch_dir2(t_elem *e, char **elem_path, int *flag)
{
	if (!ft_strncmp(elem_path[0], "SO", 2)
		&& ft_strlen(elem_path[0]) == 2 && !flag[2])
	{
		e->so_path = elem_path[1];
		flag[2] = 1;
		return (1);
	}
	else if (!ft_strncmp(elem_path[0], "NO", 2)
		&& ft_strlen(elem_path[0]) == 2 && !flag[3])
	{
		e->no_path = elem_path[1];
		flag[3] = 1;
		return (1);
	}
	return (0);
}

static int	ft_ch_color(t_elem *e, char **elem_path, int *flag)
{
	if (!ft_strncmp(elem_path[0], "F", 1)
		&& ft_strlen(elem_path[0]) == 1 && !flag[4])
	{
		parse_rgb(elem_path[1], e->ceil_col);
		flag[4] = 1;
		return (1);
	}
	else if (!ft_strncmp(elem_path[0], "C", 1)
		&& ft_strlen(elem_path[0]) == 1 && !flag[5])
	{
		flag[5] = 1;
		parse_rgb(elem_path[1], e->floor_col);
		return (1);
	}
	return (0);
}

void	ft_get_tex_path(t_elem *e, char *str, int *flag)
{
	char	**elem_path;

	if (!str)
		ft_error();
	elem_path = ft_split(str, ' ');
	ft_ch_str_cnt(elem_path, 2);
	if (ft_ch_dir(e, elem_path, flag) || ft_ch_dir2(e, elem_path, flag))
	{
	}
	else if (ft_ch_color(e, elem_path, flag))
	{
	}
	else
	{
		ft_error();
	}
	free(elem_path[0]);
	free(elem_path);
	free(str);
}
