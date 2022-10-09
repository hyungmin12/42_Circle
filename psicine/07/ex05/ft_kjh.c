#include <stdlib.h>

int	ft_cmp_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		++charset;
	}
	return (0);
}

void	ft_strcpy_until(char *s1, char *s2, char *until)
{
	while (s2 < until)
		*(s1++) = *(s2++);
	*s1 = 0;
}


long long	ft_cnt_word(char *str, char *charset)
{
	long long	cnt;

	cnt = 0;
	while (*str)
	{
		if (!ft_cmp_charset(*str, charset))
		{
			cnt++;
			while (*str && (!(ft_cmp_charset(*str, charset))))
				str++;
		}
		str++;
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	char		**tmp;
	char		*src;
	long long	idx;

	tmp = (char **)malloc(sizeof(char *) * ft_cnt_word(str, charset) + 1);
	if (!tmp)
		return (0);
	idx = 0;
	while (*str)
	{
		if (!ft_cmp_charset(*str, charset))
		{
			src = str;
			while (*str && (!ft_cmp_charset(*str, charset)))
				str++;
			tmp[idx] = (char *)malloc(str - src + 1);
			ft_strcpy_until(tmp[idx++], src, str);
		}
		str++;
	}
	tmp[idx] = 0;
	return (tmp);
}


#include<stdio.h>
int main()
{
	int i = 0;
	char **str = ft_split("asd11asdf11asdf", "11");
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}
