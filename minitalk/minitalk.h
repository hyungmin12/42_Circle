/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:16:09 by hyyoo             #+#    #+#             */
/*   Updated: 2023/01/19 17:32:31 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

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
char	*ft_error_msg(char *str);

#endif
