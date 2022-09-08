#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(long n);
int	ft_puthex(unsigned long num, char c);
void 	ft_putchar2(char c);
int     ft_len(uintptr_t n);
void    ft_putnumx(uintptr_t n);
int     ft_putx(unsigned long long p);

#endif
