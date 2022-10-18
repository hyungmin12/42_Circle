#include <stdlib.h>

int		count_word(char *str)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				i++;
			cnt++;
		}
	}
	return (cnt);
}

int		word_len(char *str, int i)
{
	int cnt;

	cnt = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
	{
		cnt++;
		i++;
	}
	return (cnt);
}

// "		 huny dwq aawdd "  // 3 (count_word), 4, 3, 6.. (word_len)
char 	**ft_split(char *str)
{
	int i;
	int j;
	int k;
	char **tab;

	i = 0;
	j = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (count_word(str) + 1))))
		return (NULL);
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
		{
			k = 0;	//초기화
			if (!(tab[j] = (char *)malloc(sizeof(char) * (word_len(str, i) + 1))))
				return (NULL);
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')	// 문자
			{
				tab[j][k] = str[i]; // segfault 
				k++;
				i++;
			}
			tab[j][k] = '\0';	//널값
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}


/*
char **str  =  malloc (sizeof(char *) * (4 + 1));
str[4] = NULL;

str -> char *  (8 byte)    의 자리만 4개!  (NULL까지 5개)

포인터!
str[0] = malloc(size(char) * (5 + 1));  => "abcdef";
*/






#include <stdio.h> // printf
void	print_split(char **str)
{
	int i = 0;
	printf("split\n");
	while (str[i])
		printf("%s\n", str[i++]);
}

int		main(void)
{
	char **tab;
	char **tab2;
		
	tab = ft_split("	 bonjour je m'appel Arthur	");
	tab2 = ft_split("		");
	print_split(tab);
	print_split(tab2);

	return (0);
}
