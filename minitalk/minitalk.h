/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:16:09 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/18 21:56:42 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/proc.h>

int		ft_atoi(const char *str);
int		is_number(char *str);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	send_bit(char origin_char, int pid);
void	send_msg(char *str, int pid);
void	print_msg(int sig);
char	*error(char *str);

#endif
