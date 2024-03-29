/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasing2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:08:12 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/18 15:10:53 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_map_extention(char *map_name)
{
	char	*ext;
	int		len;

	len = ft_strlen(map_name) - 3;
	ext = map_name + len;
	if (ft_strncmp(ext, "ber", 3) != 0)
	{
		ft_error_msg("map extention is not .ber");
		exit(1);
	}
}

void	get_num_row(char *map, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error_msg("file can't open");
	line = get_next_line(fd);
	while (line)
	{
		game->num_row++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (game->num_row < 3)
		ft_error_msg("map is empty");
}

void	str_init(char *map, t_game *game)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	get_num_row(map, game);
	game->str_line = (char **)malloc(sizeof(char *) * (game->num_row + 1));
	if (!(game->str_line))
		return ;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error_msg("file can't open");
	line = get_next_line(fd);
	while (line)
	{
		game->str_line[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	game->str_line[i] = NULL;
	close(fd);
}

void	check_param(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (game->str_line[i])
	{
		j = 0;
		while (game->str_line[i][j])
		{
			c = game->str_line[i][j];
			if (!(c == 'P' || c == '0' || c == '1' || c == 'C' || c == 'E' ))
				get_free_and_exit("param error", game);
			j++;
		}
		i++;
	}
}
