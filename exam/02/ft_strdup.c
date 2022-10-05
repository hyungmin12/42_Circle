
#include <stdlib.h>

/*
 *
 * char *str = "abcd";
 *
 * char *tmp = str;
 * 메모리공유
 *
 * str 수정 같고놀고싶어 패고싶어
 * tmp 에다가 저장.
 *
 * 문제; str[1] = 'b';
 * tmp[1] ==> 'b';
 */

// 똑같이 저장.

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	char *ret;

	// +1 중요
	ret = (char*)malloc(sizeof(char*) * (ft_strlen(str) + 1));
	if (!ret)
		return (NULL);
	
	//ft_strcpy(ret, str);
	int i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

/*
#include <stdio.h>
int main(void)
{
	char *str = "abc";
	char *ret = ft_strdup(str);
	printf("%s\n", ret);
	return (0);
}
*/
