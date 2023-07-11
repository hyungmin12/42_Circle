/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:56:00 by hyyoo             #+#    #+#             */
/*   Updated: 2023/06/29 20:43:33 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_check_file_name(char *name)
{
	if (!name)
		ft_error();
	if (ft_strlen(name) < 4)
		ft_error();
	if (ft_strncmp(".cub", name + ft_strlen(name) - 4, 4))
		ft_error();
}

static void	ft_check_position(t_info *info)
{
	int	i;
	int	j;

	j = -1;
	while (info->map.map[++j])
	{
		i = -1;
		while (info->map.map[j][++i])
		{
			if (info->map.map[j][i] == 'E' || info->map.map[j][i] == 'W'
				|| info->map.map[j][i] == 'S' || info->map.map[j][i] == 'N')
			{
				info->pos_x = j + 0.5;
				info->pos_y = i + 0.5;
				info->map.start_dir = info->map.map[j][i];
			}
		}
	}
}

void	ft_get_file_and_path(char *map_name, t_info *info)
{
	int	fd;

	ft_check_file_name(map_name);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_error();
	}
	ft_get_elem(fd, info);
	ft_get_and_check_map(fd, info);
	close(fd);
	ft_check_position(info);
}
