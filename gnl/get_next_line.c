/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:04:44 by hyyoo             #+#    #+#             */
/*   Updated: 2022/09/01 19:15:53 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*find_next_line(int fd, char *buffer, char *save_buf)
{
	int	cnt;
	char	*tmp_buf;

	cnt = 1;
	while (cnt)
	{
		cnt = read(fd, buffer, BUFFER_SIZE);
		if (cnt == -1)
			return (0);
		else if (cnt == 0)
			break ;
		buffer[cnt] = '\0';
		if (!save_buf)
		{
			save_buf = malloc(1);
			save_buf[0] = '\0';
		}
		tmp_buf = save_buf;
		save_buf = ft_strjoin(tmp_buf, buffer);
		if (!save_buf)
			return (NULL);
		free(tmp_buf);
		tmp_buf = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (save_buf);
}

static char	*ft_cut_the_line(char *str)
{
	int	i;
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
		free(ret);
		ret = NULL;
		return (NULL);
	}
	str[i + 1] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*buffer;
	static char	*save_buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	str = find_next_line(fd, buffer, save_buf);
	free(buffer);
	buffer = NULL;
	if (!str)
		return (NULL);
	save_buf = ft_cut_the_line(str);
	return (str);
}
/*
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;

   fd = 0;
   fd = open("./test", O_RDONLY);
   char *line = get_next_line(fd);
   printf("%p\n", line);
   printf("%s", get_next_line(fd));
   free(line);
   line = get_next_line(fd);
   printf("%s", line);
   free(line);

   line = get_next_line(fd);
   printf("%s", line);
   free(line);
   system("leaks a.out");
   return (0);
}*/
