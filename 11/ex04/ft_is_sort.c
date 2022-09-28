/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 03:57:24 by hyyoo             #+#    #+#             */
/*   Updated: 2022/06/07 20:38:56 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	index;
	int	tmp;

	index = 0;
	while (length-- > 1)
	{
		tmp = (*f)(tab[length], tab[length - 1]);
		if (tmp == 0)
			continue ;
		if (index == 0)
			index = tmp;
		else if ((index < 0 && tmp > 0) || (index > 0 && tmp < 0))
			return (0);
	}
	return (1);
}
