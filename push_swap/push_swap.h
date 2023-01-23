#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_num
{
	// struct s_numbers	*prev;
	int					content;
	struct s_numbers	*next;
}			t_num;

typedef struct s_info
{
	int					*array;
	int					size_a;
	struct s_numbers	*top_a;
	struct s_numbers	*bottom_a;
	int					size_b;
	struct s_numbers	*top_b;
	struct s_numbers	*bottom_b;
}			t_info;


void parsing(int ac, char **av, int *arr_size, int *nums);
int get_array_size(char **av);
int *get_num_array(char **av, int size);
int get_split_size(char **split_str);
void free_str(char **str);
int ft_is_space(char c);
int ft_str_space(char *str);
void ft_error_msg(char *msg);
void check_is_digit(const char *str);
void check_is_sorted(int *nums, int size);
void    check_is_overlap(int *nums, int size);

#endif