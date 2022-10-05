


/* test function for (*f) */

// void (*f)(void *) 에서 알수있듯이
// 반환값은 void, 즉 없고
// 받는 파라미터는 void *임.
// 그냥 함수는 예중에 하나이므로 참고만해도됨

#include <stdio.h>

void	print_str(void	*str)
{
	char *copy_str;

	copy_str = (char *)str;
	printf("%s\n", copy_str);
}



/* test function for (*f) */



#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		// list_size와 비슷하지만 다른점은
		// 그냥 (*f)함수에 data를 넣어서 한번 실행시키는것뿐
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}


/* test main */
#include <stdlib.h>	// malloc
#include <string.h>	// strdup
int main(void)
{
	t_list	*list_1;
	list_1 = (t_list *)malloc(sizeof(t_list));
	list_1->next = NULL;
	list_1->data = strdup("hyung");


	t_list	*list_2;
	list_2 = (t_list *)malloc(sizeof(t_list));
	list_2->next = NULL;
	list_2->data = strdup("jun");
	
	t_list	*list_3;
	list_3 = (t_list *)malloc(sizeof(t_list));
	list_3->next = NULL;
	list_3->data = strdup("yoo");


	/* link */
	/* 1 -> 2  */
	list_1->next = list_2;
	/* 2 -> 3 */
	list_2->next = list_3;

	ft_list_foreach(list_1, &print_str);


	return (0);
}
