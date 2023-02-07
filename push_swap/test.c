#include <stdlib.h>  // system, atexit 함수를 사용하기 위해 추가.
#include <string.h>
#include <stdio.h>

// 프로그램 바깥 터미널에서 leaks 명령어를 수행한다
// (컴파일 후 프로그램의 이름은 기본 a.out으로 설정).
void	check_leak(void)
{
	system("leaks --list -- a.out");
}

char	*get_sentence(void)
{
	char	*string;
	char	sentence[] = "Omae wa mou shindeiru...";

	string = malloc(sizeof(char) * 44);
	strcpy(string, sentence);
	return (string);
}

int	main(void)
{
	char	*str_ptr;

	str_ptr = get_sentence();
	printf("%s\n", str_ptr);
	printf("NANI?!\n");
	printf("=====================\n");
  // 프로그램이 종료되면 아래 함수를 호출한다.
	atexit(check_leak);
	return (0);
}