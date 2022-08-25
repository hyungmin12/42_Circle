#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
static int	ft_strlen(char *str);
int	ft_putnbr(int n, int *i);

#endif
