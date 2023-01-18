#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_node {
    int content;
    struct s_node *prev;
    struct s_node *next;
} t_node;

void parcing(int ac, char **av);
int *ft_atoi_and_rt(char **av, int *num_array, int num_array_size);

#endif