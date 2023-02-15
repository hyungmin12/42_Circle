/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:40:46 by hyyoo             #+#    #+#             */
/*   Updated: 2023/02/15 22:09:07 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void    ft_error_msg()
{
	printf("Error\n");
	exit(1);
}

t_info	*ft_init_info(t_info *info)
{
	info = (t_info *)malloc(sizeof(t_info));
	info->one = 0;
	info->two = 0;
	info->thr = 0;
	info->four = 0;
	info->five = 0;

	return (info);
}

int	main(int ac, char **av)
{
	t_info	*info;

	info = NULL;
	info = ft_init_info(info);

	if (ac < 5 || ac > 6)
		ft_error_msg();
	parcing(ac, av, info);

	return (0);
}
