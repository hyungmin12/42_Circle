/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:00:01 by hyyoo             #+#    #+#             */
/*   Updated: 2023/06/29 20:44:05 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_check_flag(int *flag)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (!flag[i])
			return (0);
	}
	return (1);
}

void	ft_init_flag(int *flag)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		flag[i] = 0;
		i++;
	}
}

void	ft_get_elem(int fd, t_info *info)
{
	int		flag[6];
	char	*str;
	char	*tmp;

	ft_init_flag(flag);
	while (42)
	{
		if (ft_check_flag(flag))
		{
			break ;
		}
		str = get_next_line(fd);
		if (!str || str[ft_strlen(str) - 1] != '\n')
			ft_error();
		if (str[0] == '\n' && ft_strlen(str) == 1)
		{
			free(str);
			continue ;
		}
		tmp = str;
		str = ft_substr(str, 0, ft_strlen(str) - 1);
		free(tmp);
		ft_get_tex_path(&info->element, str, flag);
	}
}
