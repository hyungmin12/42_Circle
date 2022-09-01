/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:20:59 by hyyoo             #+#    #+#             */
/*   Updated: 2022/09/01 17:36:07 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1. 읽어들일 문자열. buf..
// 2. 문자열을 저장. save_buf
// 3. char *get_next_line(int fd) 함수 원형

#include "get_next_line.h"

static char	*ft_read_buf(int fd, char *buf, char *save_buf) // buf 저장
{
	char	*tmp_buf;
	int		read_size;

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
		free(tmp_buf);
		tmp_buf = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (save_buf);
}

static char	*ft_cut_line(char *str) // 개행구분
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
		free(ret);
		ret = NULL;
		return (NULL);
	}
	str[i + 1] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	char			*buf;
	static char		*save_buf;
	char			*only_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); // buf할당
	if (!buf)
		return (NULL);
	only_line = ft_read_buf(fd, buf, save_buf);
	free(buf);
	buf = NULL;
	if (!only_line)
		return (NULL);
	save_buf = ft_cut_line(only_line);
	
	return (only_line);
}

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
}
