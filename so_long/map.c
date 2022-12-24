/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 23:33:18 by hyyoo             #+#    #+#             */
/*   Updated: 2022/12/25 00:23:14 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void init_line(t_game *g, char *line)
{
    g->hei = 0;
    g->walk_cnt = 0;
    g->wid = ft_strlen(line) - 1;
}

void read_map(char *map_name, t_game *g)
{
    int     fd;
    char    *line;
    
    fd = open(map_name, O_RDONLY);
    if (fd <= 0)
        print_error("Can't open");
    line = get_next_line(fd);
    init_line(g, line);
    g->str_line = ft_strdup_without_newline(line);
    free(line);
    while (line)
    {
        g->hei++;
        line = get_next_line(fd);
        if (line)
            g->str_line = ft_strjoin_without_newline(g->str_line, line);
    }
    close (fd);
}

void map_error_msg(int exit, int player, t_game *g)
{
    if (exit == 0)
        print_error("No exit");
    if (player == 0)
        print_error("No player");
    if (g->all_col == 0)
        print_error("No collection");
}

void    check_params(t_game *g)
{
    int i;
    int exit;
    int player;

    i       = 0;
    exit    = 0;
    player  = 0;
    g->all_col = 0;
    g->col_cnt = 0;
    while (i < ft_strlen(g->str_line))
    {
        if (g->str_line == 'E')
            exit++;
        else if (g->str_line == 'P')
            player++;
        else if (g->str_line == 'C')
            g->all_col++;
        i++;
    }
    map_error_msg(exit, player, g);
}

int check_walls(t_game *g)
{
	int			i;
	const int	len = ft_strlen(g->str_line); //const 꼭 써야하나?..
    const int   row = g->hei
	const int	col = len / row;

	i = 0;
	while (i < len / row)
	{
		if (str[i] != '1' || str[len - i - 1] != '1')
			return (0);
		i++;
	}
	i = col;
	while (i < col * (row - 1))
	{
		if (str[i] != '1' || str[i + col - 1] != '1')
			return (0);
		i += col;
	}
	return (1);
}

void    map_check(t_game *g)
{
    int i;
    int j;

    i = ft_strlen(g->str_line);
    j = g->hei * g->wid;
    if (i != j)
        print_error("Map is not rectangle");
    if (!check_wall(g));
        print_error("Map must be closed/wall");
    check_params(g);
}