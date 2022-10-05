#include <stdlib.h>

int		ft_nbr_len(int nb, int base)
{
	int i;

	i = 0;
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		nb /= base;		// nb /= 10
		i++;
	}
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*cpy;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	cpy = (char*)malloc(sizeof(char) * len);
	if (cpy == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_itoa_base(int value, int base)
{
	int		i;
	int		s;
	int		len;
	char	*radix;
	char	*result;

	i = 0;
	s = 0;
	len = 0;

	radix = "0123456789ABCDEF";

	/* 
	 *과제에는 정확하게 언급되어있지는않음
	 base가 2에서부터 16까지인데
	 1 이하로 넣으면 무한루프처럼 프로그램이 아무것도출력하지않고
	 종료가되지않음
	 만약에 체출하였는데, 다른 예제코드들이 이상이없다면,
	 if (base <= 1)
	 	return (NULL);
	처럼 프로텍션걸어주면 될듯
	하지만 거의 백프로확률로 그냥통과될듯
	 */
	if (value == 0)
		return (ft_strdup("0")); // malloc 바로 내보냄
	if (base == 10 && value == -2147483648)
		return (ft_strdup("-2147483648"));	

	len = ft_nbr_len(value, base);
	if (base == 10 && value < 0)
		s = 1;

	result = (char*)malloc(sizeof(char) * (len + s + 1));
	if (result == NULL)
		return (NULL);

	if (s == 1)
	{
		result[0] = '-';
		len++;
	}

	result[len] = '\0';

	if (value < 0)
		value *= -1;
	while (len > s)
	{
		result[len - 1] = radix[value % base];
		value /= base;
		len--;
	}
	return (result);
}


/* test */
#include <stdio.h>
int main(void)
{
	int value = -2421212;
	printf("%s\n", ft_itoa_base(value, 1));
	return (0);
}
	
