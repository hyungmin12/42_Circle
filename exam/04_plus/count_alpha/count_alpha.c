#include <stdio.h>

int is_lower(int c)
{
    return c >= 'a' && c <= 'z';
}

int is_upper(int c)
{
    return c >= 'A' && c <= 'Z';
}

int is_alpha(int c)
{
    return is_lower(c) || is_upper(c);
}

int ft_strlen(char *str)
{
    int ret = 0;

    while (str[ret])
        ret++;
    return ret;
}

void    set_lower(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (is_upper(str[i]))
            str[i] += 32;
        i++;
    }
}

#include <unistd.h>
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        char *str = argv[1];
	// 대문자와 소문자 둘다 같은 문자로 읽히니
	// 대문자를 우선 소문자로 치환
        set_lower(str);

	// 앞으로 중간중간, 해결된부분은 널값으로 넣어주는것이니
	// len을 구해서 0부터 len까지 돈다. str[i]는 안됨
        int len = ft_strlen(str);
       
	char c;
        int i = 0; 
	int n = 0;
        
	while (i < len)	// str이 원래 "abcade"였다면, a를 만나고 "a#bc#de" (여기서 #은 '\0'값으로 바꾸지만 임의로 쓰레기값이들이감.  운영체제마다 쓰레기값이다르기때문에 예로 #을 넣어둠. 그렇기때문에 "a'\0'bc'\0'de"로 바뀌니깐, while(str[i])로 하면 끝까지 루프를 돌수가없음. 그렇기때문에 i < len 으로 쓴거임
        {
	    c = str[i];
            if (is_alpha(c))	//str[i]가 알파벳이라면
            {
		   /* 디버깅용 */
		   /*
		write(1, "char == ", 8);
		write(1, &c, 1);
		write(1, "\n", 1);
		*/
                int tmp = i;	//i 인덱스는 tmp에 저장하고 tmp으로 루프를돌면서, c와 같은 char를 널값으로 바꾸면서 count를 ++해준다
                int count = 0;
                while (tmp < len)	// 인덱스는 tmp, 즉 원래 i인덱스부터 시작한다. c가 'k'라면, 그때가 'k'를 처음만난 순간으므로 그때부터 마지막 인덱스까지 루프를 돈다
                {
                    if (str[tmp] == c) // 루프중에 c를 만난다면!
                    {
                        count++;	// 하나씩 카운트 업
                        str[tmp] = 0;	// 널값으로 바꾼다.
                    }
                    tmp++;	// 루프를 돌기위해서 ++
                }
		/*
		 * 각각 한바퀴돌고난후에 어떻게 스트링이 바뀌는지 출력하는것
		 */
		// 단, write 와 printf 가 출력속도가 다르기때문에 출력순서는 다름
		//write(1, str, len);
		//write(1, "\n", 1);
                if (n) // 첫 문자만제외하고 ", "를 출력한후에 카운트와 알파벳출력
                    printf(", ");
                printf("%d%c", count, c);	// 받은값 출력.
                n++;
            }
            i++;
        }
    }
    printf("\n");
}


/*
 * 예)
 * "42abcabc"
 * i가 2일때, a를 만나고, 알파벳이므로
 * 루프를 돌면서
 * "42#bc#bc" 로 변환, 그리고 a2가출력! i++이므로 i는 3
 * 루프를 다시 돌면서
 * str[3] == 'b' 즉 알파벳이므로 위와같이
 * "42##c##c" 가 된다. n은 0이아니므로, ", "출력후 2b출력!
 */
