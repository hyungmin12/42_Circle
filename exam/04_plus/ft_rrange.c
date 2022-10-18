/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
 */


#include <stdlib.h>

int		ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int		*ft_rrange(int start, int end)
{
	int i;
	int *tab;

	i = 0;
	tab = (int*)malloc(sizeof(int) * ft_abs(end - start) + 1);
	while (end > start)
	{
		tab[i] = end;
		end--;
		i++;
	}
	tab[i] = end;
	while (end < start)
	{
		tab[i] = end;
		end++;
		i++;
	}
	tab[i] = end;
	return (tab);
}










// 후보 2
#include <stdlib.h>

int		*ft_rrange(int start, int end)
{
	int		*rrange;
	int		i;

	if (start > end)
		rrange = (int *)malloc(sizeof(int) * (start - end) + 1);
	else
		rrange = (int *)malloc(sizeof(int) * (end - start) + 1);
	i = 0;
	while (start != end)
	{
		rrange[i++] = end;
		end -= (start > end) ? -1 : 1;
	}
	rrange[i] = end;
	return (rrange);
}
