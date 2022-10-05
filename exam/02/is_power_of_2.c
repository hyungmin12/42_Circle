

/*
 *Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);
*/

// 2의 배수




























// 함수니깐 main 만드는거아니고
// power of 2는 2의 거듭제곱
// 
// 1, 2, 4, 8, 16, 32 .. 
//
// 

int		is_power_of_2(unsigned int n)
{
	if (n == 0)	// 꼭 해줘야함, 아니면 무한루프걸림
		return (0);

	while (n % 2 == 0)
	{
		n /= 2;  
	}

	/*
	 * n == 2일때, 2 % 2 = 0 이므로 루프에 들어가서 n = 1이됨, 1 % 2 == 1
	 *
	 * n = 3 일때, 3 % 2 = 1 이므로, n은 3으로 루프에 못들어가고 나옴
	 * n = 5 일때, 5 % 2 = 1 이므로, n은 5으로 루프에 못들어가고 나옴
	 * n = 7 일때, 7 % 2 = 1 이므로, n은 7으로 루프에 못들어가고 나옴
	 */

	if (n == 1)
		return (1);
	else
		return (0); 
}


// test
//
#include <stdio.h>
int main(void)
{
	printf("0 은 거듭제곱? %d\n",  is_power_of_2(0));
	printf("1 은 거듭제곱? %d\n",  is_power_of_2(1));
	printf("2 은 거듭제곱? %d\n",  is_power_of_2(2));
	printf("6 은 거듭제곱? %d\n",  is_power_of_2(6));
	printf("32 은 거듭제곱? %d\n",  is_power_of_2(32));
	return (0);
}

