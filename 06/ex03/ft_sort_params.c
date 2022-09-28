/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 05:19:45 by hyyoo             #+#    #+#             */
/*   Updated: 2022/05/30 05:19:49 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_changement(int ac, char **av)
{
	int			i;
	int			j;
	char		*temp;

	j = 1;
	i = ac - 1;
	while (i > 0)
	{
		while (j < i)
		{
			if ((ft_strcmp(av[j + 1], av[j]) < 0))
			{
				temp = av[j];
				av[j] = av[j + 1];
				av[j + 1] = temp;
			}
			j++;
		}
		j = 1;
		i--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	ft_changement(argc, argv);
	while (i < argc)
	{
		while (*argv[i])
		{
			write(1, argv[i], 1);
			argv[i]++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
