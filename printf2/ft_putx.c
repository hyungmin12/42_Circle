#include "ft_printf.h"

void	ft_putchar2(char c)
{
	write(1, &c, 1);
}

int	ft_len(uintptr_t n)
{
	int	i;

	i = 0;
	while (n)
	{
		i++;
		n /= 16;
	}
	return (i);
}

void	ft_putnumx(uintptr_t n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n > 15)
	{
		ft_putnumx(n / 16);
		ft_putnumx(n % 16);
	}
	else
		write(1, &hex[n], 1);
}

int	ft_putx(unsigned long long p)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	if (p == 0)
		i += write(1, "0", 1);
	else
	{
		ft_putnumx(p);
		i += ft_len(p);
	}
	return (i);
}
