/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhyeongmin <yuhyeongmin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 23:58:03 by hyyoo             #+#    #+#             */
/*   Updated: 2022/12/28 14:51:37 by yuhyeongmin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(long n);
int		ft_puthex(unsigned long num, char c);
int		ft_len(unsigned long long n);
int		ft_putx(unsigned long long p);
void	ft_putchar2(char c);
void	ft_putnumx(unsigned long long n);
int     ft_printf(const char *str, ...);

#endif
