/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:27:36 by hyyoo             #+#    #+#             */
/*   Updated: 2022/06/07 03:45:51 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int			i;
	int			j;
	int			size;
	char		*temp;

	i = 0;
	j = 0;
	size = ft_strlen(tab);
	while (i < size - 1)
	{
		while (j < size - 1 - i)
		{
			if ((*cmp)(tab[j], tab[j + 1]) > 0)
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
		j = 0;
	}
}
