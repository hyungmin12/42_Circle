
/*
 
Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

 */


// .h 파일과 .c 파일 두개 작성
//


// !! 꼭 헤더 넣어주기, 중복이어도 #ifndef때문에상관없으니
// 꼭 해주기
#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	t_list	*list;
	int		i;

	list = begin_list;
	i = 0;
	while (list)		// list *a  -> 초기화 next = NULL; 생기면 연결
	{
		list = list->next;
		i++;
	}
	return (i);
}


/* test main */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	/* list 3개 선언 */
	t_list	*list_1;
	list_1 = (t_list *)malloc(sizeof(t_list));
	list_1->next = NULL;
	list_1->data = 0;


	t_list	*list_2;
	list_2 = (t_list *)malloc(sizeof(t_list));
	list_2->next = NULL;
	list_2->data = 0;

	t_list	*list_3;
	list_3 = (t_list *)malloc(sizeof(t_list));
	list_3->next = NULL;
	list_3->data = 0;

	/* 1, 2 연결 / 2, 3 연결 */
	list_1->next = list_2;
	
	list_2->next = list_3;

	/* 사이즈 출력 */
	printf("size == %d\n", ft_list_size(list_1));}





