/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:31:34 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/07 12:06:02 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_map_extention(char *map_name)
{
	char	*ext;
	int	len;

	len = ft_strlen(map_name) - 3;
	ext = map_name + len;
	if (ft_strncmp(ext, "ber", 3) != 0)
		return (ft_error_msg("map extention is not .ber"));
	return (SUCCESS);
}

int	get_num_row(char *map, t_game *game)
{
	int	fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (ft_error_msg("file can't open"));
	line = get_next_line(fd);
	while (line)
	{
		game->num_row++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (game->num_row < 3)
		return (ft_error_msg("map is empty"));
	return (SUCCESS);

}

int	str_init(char *map, t_game *game)
{
	int	fd;
	int	i;
	char	*line;

	i = 0;
	get_num_row(map, game);
	game->str_line = (char **)malloc(sizeof(char *) * (game->num_row + 1));
	if (!(game->str_line))
		return (ERROR);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (ft_error_msg("file can't open"));
	line = get_next_line(fd);
	while (line)
	{
		game->str_line[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	game->str_line[i] = NULL;
	close(fd);
	return (SUCCESS);
}

int	check_param(t_game *game)
{
	int	i;
	int	j;
	char	c;

	i = 0;
	while (game->str_line[i])
	{
		j = 0;
		while (game->str_line[i][j])
		{
			c = game->str_line[i][j];
			if (!(c == 'P' || c == '0' || c == '1' || c == 'C' || c == 'E' ))
				return (ft_error_msg("param error"));
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_param_cnt(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->str_line[++i])
	{
		j = -1;
		while (game->str_line[i][++j])
		{
			if (game->str_line[i][j] == 'P')
			{
				game->player++;
				game->player_x = j;
				game->player_y = i;
			}
			else if (game->str_line[i][j] == 'E')
				game->exit++;
			else if (game->str_line[i][j] == 'C')
				game->collec++;
		}
	}
	if (!(game->player == 1 && game->exit == 1 && game->collec >= 1))
		return (ft_error_msg("param cnt error"));
	return (SUCCESS);
}

int	check_requ(t_game *game)
{
	int	i;

	i = 0;
	game->num_col = (int)ft_strlen(game->str_line[0]);
	while (game->str_line[i])
	{
		if (game->num_col != (int)ft_strlen(game->str_line[i++]))
			return (ft_error_msg("map is not requ"));
	}
	return (SUCCESS);
}

int	check_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->str_line[i])
	{
		j = 0;
		while (game->str_line[i][j])
		{
			if ((i == 0 || i == game->num_row - 1)
				|| (j == 0 || j == game->num_col - 1))
			{
				if (game->str_line[i][j] != '1')
					return (ft_error_msg("wall error"));
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

void	parsing(char *map, t_game *game)
{
	int result;

	result = check_map_extention(map) + str_init(map, game)
		+ check_param(game) + check_param_cnt(game)
			+ check_requ(game) + check_wall(game);
	if (result)
	{
		free_table(game->str_line);
		exit(1);
	}
}
