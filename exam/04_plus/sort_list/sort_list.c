
#include "list.h"

/* test function 시험에는 넣으면 안됨 */
int ascending(int a, int b) // function used to compare a and b and return 1 if they are in ascending order or else 0.
{
	return (a <= b);
}
/* test function 시험에는 넣으면 안됨 */
void ft_swap(int *c, int *d) // swap funtion used to swap the data of c and d.
{
	int temp;
	temp = *c;
	*c = *d;
	*d = temp;
}
/*////////////////////////////////// 여기까지 안봐도됨//////////////////// */


t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *begin = lst; 
	t_list *future; 
	while(lst)
	{
		future = lst->next;
		while (future)
		{
			if (!cmp(lst->data, future->data))
				ft_swap(&lst->data, &future->data);
			future = future->next;
		}
		lst = lst->next;
	}
	return (begin);
}
