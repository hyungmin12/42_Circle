/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:56:31 by hyyoo             #+#    #+#             */
/*   Updated: 2023/06/29 20:44:20 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	map_newline_check(char *str)
{
	int	first_flag;
	int	i;

	first_flag = 1;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			if (first_flag)
				continue ;
			else
				ft_error();
		}
		else if (str[i] == '\n')
			continue ;
		else
			first_flag = 0;
	}
}

void	ft_get_and_check_map(int fd, t_info *info)
{
	char	*all_str;
	char	*tmp;
	char	*str;

	all_str = ft_strdup("");
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		tmp = all_str;
		all_str = ft_strjoin(all_str, str);
		free(tmp);
		free(str);
	}
	map_newline_check(all_str);
	info->map.map = ft_split(all_str, '\n');
	free(all_str);
	check_world_map(info->map.map);
}
