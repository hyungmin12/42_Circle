#include <stdlib.h>

int	ft_len(long long n, int base_len);
int	ft_check(char *base, int *len);
int	ft_space(char c);

char	*ft_putnbr_base(int n, char *base, int b_len)
{
	int		size;
	long long	tmp;
	char		*ret;

	tmp = n;
	size = ft_len(tmp, b_len);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size] = '\0';
	if (n < 0)
	{
		ret[0] = '-';
		n = n * -1;
	}
	if (n == 0)
	{
		ret[0] = base[0];
		return (ret);
	}
	if (tmp < 0)
		tmp *= -1;
	while (tmp)
	{
		ret[--size] = base[tmp % b_len];
		tmp /= b_len;
	}
	return (ret);
}

int	ft_atoi_base(char *str, char *base, int b_len)
{
	int	ret;
	int	sign;
	int	i;

	ret = 0;
	sign = 1;
	while (ft_space(*str))
		++str;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (*str)
	{
		i = -1;
		while (++i < b_len)
		{
			if (*str == base[i])
				break ;
		}
		if (i == b_len)
			break ;
		ret = ret * b_len + i;
		++str;
	}
	return (ret * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	ft_len_from;
	int	ft_len_to;

	if (!ft_check(base_from, &ft_len_from)
		|| !ft_check(base_to, &ft_len_to))
		return (0);
	return (ft_putnbr_base(ft_atoi_base(nbr, base_from, ft_len_from),
			base_to, ft_len_to));
}
#include<stdio.h>
int main()
{
	printf("%s", ft_convert_base("11", "01","0123456789"));
}
