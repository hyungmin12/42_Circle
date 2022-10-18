/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 03:57:24 by hyyoo             #+#    #+#             */
/*   Updated: 2022/10/18 14:42:12 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int)) // 1 3이라면 -, 같으면 0,  3 1 이면 +
{
	int	index;
	int	tmp;

	index = 0;
	while (length-- > 1) //후순위 연산자 length--
	{
		tmp = (*f)(tab[length], tab[length - 1]); //끝에서부터 비교
		if (tmp == 0) // 만약 tab[length], tab[length - 1] 이 같다면
			continue ; //반복문 계속 ㄱ
		if (index == 0) // 처음에 무조건 index 에 tmp 를 대입
			index = tmp;
		else if ((index < 0 && tmp > 0) || (index > 0 && tmp < 0)) 
// 24번줄에서 무조건 index에 tmp가들어가게 되고 반복문을 한바퀴 돈후 else if로 들어감
// 그럼 이제 tmp의 값은 그 다음 tab[length]와 tab[lenghth-1] 을 비교한 값을 가지게 되고
// 처음 비교한 값인 tmp를 가진 index와 tmp의 +-(부호)가 다르다는건 정렬이 안되어 있다는것.
// 그래서 return 0 
			return (0);
	}
	return (1); //반복문을 다 돌았는데 리턴이 안됐으면 정렬이 된거니 리턴 1
}
