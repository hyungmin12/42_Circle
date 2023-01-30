#include "push_swap.h"

void    top_push(t_info *info, t_num *node, int max, int i)
{
    if (node->content == max)
    {
        if ((int)(info->size_b / 2) < i)
        {
            while (i < info->size_b)
            {
                ft_rrb(info);
                i++;
            }
            return ;
        }
        else
        {
            while (i > 0)
            {
                ft_rb(info);
                i--;
            }
            return ;
        }
    }
}
void    max_top(t_info *info)
{
    int     i;
    int     max;
    t_num  *node;
    i = 0;
    max = info->size_b - 1;
    node = info->top_b;
    int j = 0;
    while (j < info->size_b)//원래는 node != NULL
    {
        top_push(info, node, max, i);
        node = node->next;
        i++;
        j++;
    }
}
void    push_a(t_info *info)
{
    while (info->size_b != 0)
    {
        max_top(info);
        ft_pa(info);
    }
}
void    push_b(t_info *info, int chunk)
{
    int i;

    i = 0;
    while (info->size_a != 0)
    {
        if (info->top_a->content <= i)
        {
            ft_pb(info);
            i++;
        }
        else if (info->top_a->content > i && info->top_a->content <= i + chunk)
        {
            ft_pb(info);
            ft_rb(info);
            i++;
        }
        else if (info->top_a->content > i + chunk)
        {
            if (info->size_a / 2 < i)
                ft_ra(info);
            else
                ft_rra(info);
        }
    }
}

void ft_sort_every_nums(t_info *info)
{
		info->bottom_a->next = NULL;
		// info->top_a->prev = NULL;
		info->bottom_b->next = NULL;
		// info->top_b->next = NULL;

		int chunk;
		chunk = 0.000000053 * info->size_a * info->size_a + 0.03 * info->size_a + 14.5;
		// stack_a(info);
		push_b(info, chunk);
        push_a(info);
		// free_stack_b(info);

		// stack_b(info);
		// stack_a(info);
}