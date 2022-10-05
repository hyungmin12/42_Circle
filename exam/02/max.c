
/*
Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/


int		max(int *tab, unsigned int len)
{
	int	max;

	if (!len)
		return (0);

	unsigned int i = 0;
	max = tab[i]; 

	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}





// test main
//
#include <stdio.h>
#include <stdlib.h>
int		main(void)//
{//
	int	*tab;//

	if (!(tab = (int*)malloc(sizeof(int) * 3)))//
		return (0);//
	tab[0] = 7;//
	tab[1] = 6;//
	tab[2] = 9;//
	printf("%d", max(tab, 3));//
	return (0);//
}//
