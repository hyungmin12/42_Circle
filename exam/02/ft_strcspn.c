/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);

*/

/*
 *  첫번쨰인자  "abcdefg1234"
 *
 *  두번째인자 "ymgk"
 */

// s == "abcd1dwjlqd"    i  = 0
//
// reject = "Aq5";			i_re
//
/*
 *
 * 1. a -> A,q,5
 * 2. b -> A,q,5
 * 3.....
 *
 *
 * i = 0;
 * s[i] = 'a';
 * i_re = 0; reject[i_re] = 'A;
 * i_re++;
 * i_re = 1; reject[i+re] = 'q';
 * i_re++;
 * i_re = 2; reject[i_re] = '5';
 * 
 * 초기화안하면 i_re = 2;
 * 
 * i = 1;
 * str[i]랑.. 나머지도 reject[2] ]랑만비교
 */
// a ->  A q 5
// b 
// c
// d
// 1
// d
// w
// h
//..
//q    몇번째
//



#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i;
	size_t i_re;

	i = 0;
	i_re = 0;
	while (s[i] != '\0')
	{
		i_re = 0; // reject   // reset!!
		while (reject[i_re] != '\0')
		{
			if (s[i] == reject[i_re])
				return (i);
			i_re++; // 3;
		}
		i++;
	}
	// strlen
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

#include <string.h>
int main(void)
{
	char str[] = "abcdefg";
	char s1[] = "123f";
	char s2[] = "098";
	printf("%lu\n", strcspn(str, s1));
	printf("ft= %lu\n", ft_strcspn(str, s1));	//	f위치
	printf("%lu\n", strcspn(str, s2));
	printf("ft = %lu\n", ft_strcspn(str, s2)); // str길이
	return (0);
}
