
   
void	sort_int_tab(int *tab, unsigned int size);

#include <stdio.h>

int main(void)
{
	int test[] = {1, 19, 32, -123, 0, 2};

	sort_int_tab(test, 6);

	for (int i = 0;i < 6; i++)
		printf("%d\n", test[i]);
	return (0);
}
