#include <stdlib.h>

int			ft_is_charset(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
			return (1);
	return (0);
}

long long	ft_word_count(char *str)
{
	long long count;

	count = 0;
	while (*str)
	{
		if (!ft_is_charset(*str))
		{
			count++;
			while (*str && (!(ft_is_charset(*str))))
				str++;
		}
		str++;
	}
	return (count);
}

void		ft_strcpy(char *dest, char *src, char *until)
{
	while (src < until)
		*(dest++) = *(src++);
	*dest = 0;
}

char		**ft_split(char *str)
{
	char		**ret;
	long long	idx;
	char		*src;

	ret = (char **)malloc(sizeof(char *) * ft_word_count(str) + 1);
	idx = 0;
	while (*str)
	{
		if (!ft_is_charset(*str))
		{
			src = str;
			while (*str && (!ft_is_charset(*str)))
				str++;
			ret[idx] = (char *)malloc(str - src + 1);
			ft_strcpy(ret[idx++], src, str);
		}
		str++;
	}
	ret[idx] = 0;
	return (ret);
}
