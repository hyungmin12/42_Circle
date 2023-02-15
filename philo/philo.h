#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
typedef struct	s_info
{
	int	one;
	int	two;
	int	thr;
	int	four;
	int	five;
}	t_info;


void    parcing(int ac, char **av, t_info *info);
void	check_is_int(char **av);
int	ft_atoi(const char *str);
void    ft_error_msg();

#endif