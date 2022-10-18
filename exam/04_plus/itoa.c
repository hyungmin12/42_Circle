#include <stdlib.h>
#include <stdio.h>

int	len(long nb)
{
	int	len = 0;
	if (nb == 0)		//	0일때 예외처리 중요
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return(len);
}
char	*ft_itoa(int nb)
{
	char	*str;
	long	n;
	int	i;

	n = nb;
	i = len(n);
	if(!(str = (char *)malloc(i + 1)))
		return(0);
	str[i] = '\0';
	i--;
	if (n == 0)
	{
		str[0] = 48;
		return(str);	//	끝
	}
	if(n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}
	return (str);
}

int	main(void)
{
	printf("%s\n", ft_itoa(1342345));
	printf("%s\n", ft_itoa(-1342345));
	printf("%s\n", ft_itoa(+-1342345));
	printf("%s\n", ft_itoa(0));
	return (0);
}
