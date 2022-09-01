/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:46:26 by hyyoo             #+#    #+#             */
/*   Updated: 2022/09/01 20:01:08 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// 1. gnl 함수에서 할것 == 
// 2. 개행을 포함한 버퍼사이즈 만큼의 배열을 찾고, 저장한다.
// 3. 저장한 배열을 받아서 개행을 기준으로 자른후 리턴한다.

#include "get_next_line.h"

static void str_free(char *str)
{
	free(str);
	str = NULL; // 메모리는 해제 하더라도 그곳의 주소값은 여전하기에 NULL을 가르치게 한다.
}

/*static int	check_size(int read_size)
{
	if (read_size == -1)
		return (0);
	else
		return (1);
}*/

static char	*ft_read_buf(int fd, char *buf, char *save_buf)
{
	int	read_size;
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
			save_buf = ft_strdup("");
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

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); // buf할당
	if (!buf)
		return (NULL);
	str = ft_read_buf(fd, buf, save_buf);
	str_free(buf);
	if (!str)
		return (NULL);
	save_buf = ft_cut(str);

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
   //systeam("leaks a.out");
   return (0);
}*/
