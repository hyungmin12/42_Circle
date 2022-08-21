/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:30:23 by dapark            #+#    #+#             */
/*   Updated: 2022/08/18 21:29:47 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
 #define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
char    *ft_substr(char const *s, unsigned int start, size_t len);
size_t  ft_strlen(const char *str);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strchr(const char *s, int c);
size_t  ft_len(char const *src, unsigned int idx, size_t len);

#endif