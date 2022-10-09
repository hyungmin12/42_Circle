#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_size_of_str(int size, char **str, char *sep)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i] && i < size)
	{
		j = 0;
		while (str[i][j])
		{
			cnt++;
			j++;
		}
		i++;
	}
	size--;
	cnt += size * ft_strlen(sep);
	return (cnt + 1);
}

char	*zero_size(char *str)
{
	str = (char *)malloc(sizeof(char) * 1);
	if (!str)
		return (0);
	str[0] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (size == 0)
		return (zero_size(join));
	join = (char *)malloc(sizeof(char) * (ft_size_of_str(size, strs, sep)));
	if (!join)
		return (0);
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			join[k++] = strs[i][j++];
		}
		j = 0;
		while (sep[j] && i != size - 1)
		{
			join[k++] = sep[j++];
		}
		i++;
	}
	join[k] = '\0';
	return (join);
}

#include<stdio.h>
int	main(void)
{
	char	*tab[4];
	tab[0] = "1";
	tab[1] = "2";
	tab[2] = "3";
	tab[3] = "4";
	printf("%s", ft_strjoin(0, tab, "Pasquale"));
	return (0);
}
