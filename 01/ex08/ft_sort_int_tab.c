/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:50:44 by hyyoo             #+#    #+#             */
/*   Updated: 2022/05/23 16:19:39 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	tamp;

	i = 0;
	while (0 <= size)
	{	
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tamp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tamp;
			}
			i++;
		}
		size--;
	}
}
