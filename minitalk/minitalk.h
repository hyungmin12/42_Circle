/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:16:09 by hyyoo             #+#    #+#             */
/*   Updated: 2022/12/29 13:39:59 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "./ft_printf/ft_printf.h"
# include <sys/proc.h>

int	ft_atoi(const char *str);
int	is_number(char *str);
int	ft_strlen(char *str);
void	send_bit(char origin_char, int pid);
void	send_msg(char *str, int pid);
void	print_msg(int sig);
char	*error(char *str);

#endif
