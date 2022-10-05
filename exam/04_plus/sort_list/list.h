#include <stdio.h>
#include <stdlib.h>
typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

t_list	*sort_list(t_list* lst, int (*cmp)(int, int)); // defination of the function.
int		ascending(int a, int b); // defination of the functional pointer which will be used to compare a and b.
