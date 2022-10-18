#include <unistd.h>

/*
$> gcc -Wall -Wall -Werror main.c print_memory.c && ./a.out | cat -e
│0000 0000 1700 0000 9600 0000 ff00 0000 ................$	
│0c00 0000 1000 0000 1500 0000 2a00 0000 ............*...$
│0000 0000 0000 0000					 $

메모리출력방식인데,
문제에서 tab이 0, 23, 150, 255...이렇게 나와있음
여기서 0 은 0000 0000, 23은 1700 0000, 150은 9600 0000, 255는 ff00 0000 으로 표현함
예를 들자면 7865 3412을 78 65 43 21 으로 나눠서, 사람이읽을때는 1234 5678으로 볼수있게한다. (나중에배움 리틀인디언, 빅인디언등등)
즉, 1700 0000은 00 00 00 17이므로, 16진수로 17은 23(십진수)이다.
*/
// unsigned char는 0 ~ 256까지를 표현한다.
// 즉 16진법으로 메모리를 표현하는데,
// 이떄 16진법으로 2자리수로 0 ~ 256을 다 표현할수있다.
void	ft_print_hex(unsigned char c)
{
	char *radix;

	radix = "0123456789abcdef";
	write(1, &radix[c / 16], 1);
	write(1, &radix[c % 16], 1);
}

void	ft_print_char(unsigned char c)
{

	if (c >= ' ' && c <= '~')
		write(1, &c, 1);
	else
		write(1, ".", 1);
}

void	print_memory(const void *addr, size_t size)
{

	unsigned char *ptr;

	i = 0;
	j = 0;
	
	ptr = (unsigned char*)addr;
	while (i < size)
	{
		j = 0;
		while (j < 16 && i + j < size)
		{
			ft_print_hex(ptr[i + j]);
			if (j % 2)
				write(1, " ", 1);
			j++;
		}
		while (j < 16)
		{
			write(1, "  ", 2);
			if (j % 2)
				write(1, " ", 1);
			j++;
		}

		j = 0;
		while (j < 16 && i + j < size)
		{
			ft_print_char(ptr[i + j]);
			j++;
		}
		write(1, "\n", 1);
		i += 16;
	}
}

/* 문제에 나와있는 테스트 메인 */
int	main(void)
{
	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}
