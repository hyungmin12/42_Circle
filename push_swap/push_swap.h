#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_num
{
	struct s_num	*prev;
	int				content;
	struct s_num	*next;
}			t_num;

typedef struct s_info
{
	int				*array;
	int				size_a;
	struct s_num	*top_a;
	struct s_num	*bottom_a;
	int				size_b;
	int				p1;
	int				p2;
	struct s_num	*top_b;
	struct s_num	*bottom_b;
}			t_info;

t_info  *ft_init_info();
t_num   *ft_init_stack();
void ft_sort(t_info *info);
void	ft_change_array_to_stack(t_info *info, int *array, int size);
int *parsing(int ac, char **av, int *arr_size, int *nums);
int get_array_size(char **av);
int *get_num_array(char **av, int size);
int get_split_size(char **split_str);
void free_str(char **str);
void ft_putstr(char *str);
int ft_is_space(char c);
int ft_str_space(char *str);
void ft_error_msg(char *msg);
void check_is_digit(const char *str);
void check_is_sorted(int *nums, int size);
void    check_is_overlap(int *nums, int size);

void ft_sa(t_info *info);
void ft_sb(t_info *info);
void ft_ss(t_info *info);
void ft_pa(t_info *info);
void	ft_pb(t_info *info);
void    ft_ra(t_info *info);
void    ft_rb(t_info *info);
void    ft_rr(t_info *info);
void ft_rra(t_info *info);
void ft_rrb(t_info *info);
void	ft_rrr(t_info *info);
void 	ft_sort_size_three(t_info *info);
void	ft_sort_every_nums(t_info *info);
void    ft_make_pibot(t_info *info);

// int	get_stack_min(t_num *stack);
// int	set_a_location_min(t_info *info);
// int	get_stack_max(t_num *stack);
// int	set_a_location_max(t_info *info);
// int	set_a_location_mid(int num, t_info *info);
// int	set_a_location(int num, t_info *info);
// void	ft_rotate_same(t_info *info, int *a, int *b);
// void	ft_rotate_a(t_info *info, int a);
// void	ft_rotate_b(t_info *info, int b);
// void	ft_sort_big_last(t_info *info);
// void	ft_sort_3div_insruct(t_info *info, int pivot1, int pivot2);
// void	ft_sort_three_division(t_info *info);
// int	ft_get_bigger(int a, int b, int a_loc, int b_loc);
// void	get_min_rotate(t_info *info, int *a, int *b);
// void	ft_sort_big(t_info *info);





#endif