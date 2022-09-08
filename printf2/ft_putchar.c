#include "./ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1); // 왜 리턴 1? 하나의 캐릭터라서? 왜?
}
