
#include "push_swap.h"

t_num   *ft_init_stack()
{
	t_num	*rt;

	rt = NULL;
	rt = (t_num *)malloc(sizeof(t_num));
	// rt->prev = NULL;
	rt->content = 0;
	rt->next = NULL;
	return (rt);
}

void	ft_change_array_to_stack(t_info *info, int *array, int size)
{
    // 첫 시작을 바텀이 가르키고 있다가 뉴 노드를 연결하면 서 뒤로 밀림. 탑과 바텀 모두 stack_a의 구조체를 가지고 있으니
    // 바텀이 맨 뒤쪽을 가르키고 있고 자연스레 탑은 밀리기 전을 가르키고 있어서 탑을 지키고 있음.
    t_num   *new_node;
    int i;

    i = 0;
    
    while (i < 5)
    {
        info->size_a++;
        new_node = ft_init_stack();
        info->top_a->content = array[size];
        info->top_a->next = new_node;
        // new_node->prev = info->bottom_a;
        new_node = info->top_a;
        size--;
        i++;
    }
    i = 0;
        new_node = ft_init_stack();
        new_node = info->top_a;
    while (i < 5)
    {
        printf("%d\n", new_node->content);
        new_node = new_node->next;
        new_node->next = new_node;
        
    }
    // free(info->top_a);
}

t_info    *ft_init_info()
{
    t_num *stack_a;
    t_num *stack_b;
    t_info *rt;

    stack_a = NULL;
    stack_b = NULL;
    rt = (t_info *)malloc(sizeof(t_info));
    rt->array = NULL;
    rt->size_a = 0;
    rt->size_b = 0;
    stack_a = ft_init_stack();
    stack_b = ft_init_stack();
    rt->top_a = stack_a;
    rt->top_b = stack_b;
    // rt->bottom_a = stack_a;
    // rt->bottom_b = stack_b;
    return (rt);
}

int main()
{
    t_info *info;
    ft_init_info();
    info->array = (int *)malloc(sizeof(int) * (5));
    // int array[10];
    // int size;

    int i = 1;
    // size = 5;
    while(i < 6)
    {
        info->array[i] = i;
        i++;
    }
    
    ft_change_array_to_stack(info, info->array, 5);
    return 0;
}