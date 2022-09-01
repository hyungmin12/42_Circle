/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:26:03 by dapark            #+#    #+#             */
/*   Updated: 2022/09/01 19:32:02 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_read_line(int fd, char *buf, char *backup)
{
  int   count;
  char  *temp_pointer;
  count = 1;
  while (count)
  {
    count = read(fd, buf, BUFFER_SIZE); // 성공시 버퍼사이즈 반환(int형 반환)
    if (count == -1) // 실패
      return (0); // read 함수를 탈출
    else if (count == 0) // eof
      break ; // while문 밖으로만 나간다
    buf[count] = '\0'; // buffer size 반환 == count
    if (!backup)
    {
		backup = malloc(1);
		backup[0] = '\0';
	}
    temp_pointer = backup; //버퍼사이즈 내에 개행이 포함되어 있을 때 개행 이후의 문자열이 나뒹굴게 되므로 그 나뒹구는 배열을 free시켜주기 위해 또 다른 포인터를 선언하여 같은 곳을 가르키게 한다.
    backup = ft_strjoin(temp_pointer, buf); // backup에 문자열 이어 붙이기 ex)bufsize = 3 이면 3개씩 계속 이어 붙인다.
    if (!backup)
      return (NULL);
    free(temp_pointer);
    temp_pointer = NULL;
    if (ft_strchr(buf, '\n')) // 개행을 만났다면 반복문 종료.
      break ;
  }
  return (backup);
}

static char *ft_extract(char *line) // 개행문자를 기점으로 문자열 자르는 함수.
{
  int   i;
  char  *result;
  i = 0;
  while (line[i] != '\n' && line[i] != '\0')
    i++; // 개행이나 문자열의 끝까지 넘기고.
  if (line[i] == '\0') // eof가 발견된다면 0을 반환
    return (0);
  result = ft_substr(line, i + 1, ft_strlen(line) - i); // 개행 이후 위치부터 backup에 저장.
  if (!result) // null가드
    return (NULL);
  if (result[0] == '\0') // 개행 이후 첫 문자가 eof라면 메모리 해제후 널 반환
  {
    free(result);
    result = NULL;
    return (NULL);
  }
  line[i + 1] = '\0'; // 읽어들인 한줄의 개행문자 위치 이전은 실질적인 데이터로, 해당줄+1 에 널값 넣어줌.
  return (result);
}

char  *get_next_line(int fd)
{
  char    *line;
  char    *buf;
  static char *backup;
  if (fd < 0 || BUFFER_SIZE <= 0)
    return (NULL);
  buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));//buffer_size 만큼 넘어감
  if (!buf)
    return (NULL);
  line = ft_read_line(fd, buf, backup);//backup배열은 비어있는 상태.
  free(buf);
  buf = NULL;
  if (!line)
    return (NULL);
  backup = ft_extract(line);
  return (line);
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
  //system("leaks a.out");
  return (0);
}
