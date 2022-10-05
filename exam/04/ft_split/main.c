
char **ft_split(char *str);

#include <stdio.h>

void	print_split(char * str_origin)
{
	int i = 0;
	char **str = ft_split(str_origin);
	printf("split of '%s'\n", str_origin);
	while (str[i])
		printf("%s\n", str[i++]);
}

int main(void)
{
	char *s1 = "	  hyung jun		dwq";
	char *s2 = "		 ";
	char *s3 = "	1234	dwdqdwq		dwqdwq end	";

	print_split(s1);
	print_split(s2);
	print_split(s3);
	return (0);
}
