
#include <unistd.h>

/*
int main(void)
{
	write(1, "z", 1);
	write(1, "\n", 1);
	return (0);
}
*/

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	write(1, "z", 1);
	write(1, "\n", 1);
	return (0);
}
