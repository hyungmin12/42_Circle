#include <stdio.h>
#include <stdlib.h>

// 

int		main(int argc, char *argv[])
{
	int		i;
	int		nbr;

	if (argc == 2)
	{
		i = 2;

		nbr = atoi(argv[1]);

		if (nbr == 1)	
			printf("1");
		while (nbr >= i)
		{
			if (nbr % i == 0)
			{
				printf("%d", i);
				if (nbr == i)
					break ;	//	끝까지간거면 while문 빠져나오기. 그래서 * 출력안됨
				printf("*");
				nbr /= i;	//	나누기
				i = 2;	//	1부터 다시시작
			}
			i++;
		}
	}
	printf("\n");
	return (0);
}



// 42
//
// i = 2 ,  nbr = 42		
// 42 % 2 -> 42 / 2 -> nbr = 21,	2*
// 21 % 2 x, 21 % 3 -> 21 /3 = nbr = 7, 2*3*
// 7 % 2, 7 % 3,  ... 7 % 7 -> nbr = 1, 2*3*7 , break! i == nbr
