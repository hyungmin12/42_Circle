/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:46:26 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/07 11:36:36 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	str_free(char *str)
{
	free(str);
	str = NULL;
}

static char	*ft_read_buf(int fd, char *buf, char *save_buf, int read_size)
{
	char	*tmp_buf;

	read_size = 1;
	while (read_size)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
			return (0);
		else if (read_size == 0)
			break ;
		buf[read_size] = '\0';
		if (!save_buf)
		{
			save_buf = malloc(1);
			save_buf[0] = '\0';
		}
		tmp_buf = save_buf;
		save_buf = ft_strjoin(tmp_buf, buf);
		if (!save_buf)
			return (NULL);
		str_free (tmp_buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (save_buf);
}

static char	*ft_cut(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (0);
	ret = ft_substr(str, i + 1, ft_strlen(str) - i);
	if (!ret)
		return (NULL);
	if (ret[0] == '\0')
	{
		str_free(ret);
		return (NULL);
	}
	str[i + 1] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	char			*buf;
	static char		*save_buf;
	char			*str;
	int				i;

	i = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	str = ft_read_buf(fd, buf, save_buf, i);
	str_free(buf);
	if (!str)
		return (NULL);
	save_buf = ft_cut(str);
	return (str);
}
