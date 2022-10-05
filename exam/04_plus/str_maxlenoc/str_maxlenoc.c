#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void ft_strcpy(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1 = '\0';
}

char *ft_strdup(char *str)
{
	char *ret;

	ret = malloc(sizeof(char) * (ft_strlen(str) + 1));
	ft_strcpy(ret, str);
	return (ret);
}

int ft_strncmp(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char *ft_strstr(char *next_str, char *copy_str)
{
	while (*next_str)
	{
		if (ft_strncmp(next_str, copy_str, ft_strlen(copy_str)))
			return (next_str);
		next_str++;
	}
	return (NULL);
}

char *tmp_str;	// 글로벌 문자열

void match_right(char *str, char *next_str)
{
	char *copy_str;

	copy_str = ft_strdup(str);
	while (*copy_str)
	{
		// 들어온 str이 abcdef라면
		// 루프를 돌수록
		// abcdef
		// abcde
		// abcd
		// abc
		// ab
		// a
		// '\0' -> while 종료
		if (ft_strstr(next_str, copy_str))
		{
			// copy_str은, 즉 abcdef가 들어온다면, match_left에서는 하나씩 앞(왼쪽)이 잘려나가고
			// match_right에서는 하니씩 뒤(오른쪽)가 잘려나간다 
			// 이것을 strstr이랑 다음 파라미터랑 비교하여, copy_str이 next_str안에 모두있다면,
			// 즉, next_str == "123abc456", copy_str = "abc"
			// 루프안으로 들어와서 tmp_str에 strdup을 해준다.
			if (ft_strlen(copy_str) > ft_strlen(tmp_str))
				tmp_str = ft_strdup(copy_str);
		}
		copy_str[ft_strlen(copy_str) - 1] = 0;
	}
}

void match_left(char *str, char *next_str)
{
	// str은 첫번째파라미터이다.
	// str이 "abcdef"라고 가정한다면,
	// str은 abcdef
	// 	bcdef
	// 	cdef
	// 	def
	// 	ef
	// 	f
	// 	순으로 match_right에 들어간다.
	while (*str)
	{
		match_right(str, next_str);
		str++;
	}
}

void maxlenoc(char **argv)
{
	char *str;

	str = *argv;
	argv++;
	while (*argv)	// 두번쨰, 세번째 파라미터 ....
	{
		// 초기값 설정
		tmp_str = "";
		match_left(str, *argv);
		if (ft_strlen(tmp_str) < ft_strlen(str))
			str = tmp_str;
		argv++;
	}
	ft_putstr(str);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		ft_putstr(argv[1]);
	if (argc > 2)
		maxlenoc(++argv);	// 프로그램이름 제외한 후에 2번쨰 부터!! 즉, 첫번쨰 파라미터
	ft_putstr("\n");
	return (0);
}
