#include<stdlib.h>

void rush(int x, int y);

int main(int ac, char **av)
{
	if(ac == 3)
	{
		int x = atoi(av[1]);
		int y = atoi(av[2]);

		rush(x, y);
	}
}
