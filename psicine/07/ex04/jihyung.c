int	ft_len(long long n, int base_len)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		n *= -1;
		++len;
	}
	while (n > 0)
	{
		++len;
		n /= base_len;
	}
	return (len);
}

int	ft_space(char c)
{
	if (c == ' ' || ('\t' <= c && c <= '\r'))
		return (1);
	return (0);
}

int	ft_check(char *base, int *len)
{
	int			check[256];
	int			i;
	char		c;

	i = 0;
	while (i < 256)
		check[i++] = 0;
	*len = 0;
	while (base[*len])
	{
		c = base[*len];
		if (check[(int)c] == 1 || ft_space(c) == 1 || c == '+' || c == '-' )
			return (0);
		check[(int)c] = 1;
		(*len)++;
	}
	if (*len <= 1)
		return (0);
	return (1);
}
