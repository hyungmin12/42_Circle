/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebikim <yebikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:55:08 by yebikim           #+#    #+#             */
/*   Updated: 2022/10/01 23:45:45 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

/*void	square(char a, char b, char c, int x)
{
	int	i;

	i = 1;
	while (i <= x)
	{
		if (i == 1)
			ft_putchar(a);
		else if (i == x)
			ft_putchar(c);
		else
			ft_putchar(b);
		i++;
	}
}

void	rush(int x, int y)
{
	int	i;

	i = 1;
	if (x < 0 || y <= 0)
		return ;
	while (i <= y)
	{
		if (i == 1)
			square('o', '-', 'o', x);
		else if (i == y)
			square('o', '-', 'o', x);
		else
			square('|', ' ', '|', x);
		ft_putchar('\n');
		i++;
	}
}*/

void	ft_putchar(char c);

void	square(char start, char middle, char end, int x)
{
	int	size;

	size = 1;
	while (size <= x)
	{
		if (size == 1)
			ft_putchar(start);
		else if (size == x)
			ft_putchar(end);
		else
			ft_putchar(middle);
		size++;
	}
}

void	rush(int x, int y)
{
	int	size;

	size = 1;
	if (x < 0 || y <= 0)
		return ;
	while (size <= y)
	{
		if (size == 1)
			square('o', '-', 'o', x);
		else if (size == y)
			square('o', '-', 'o', x);
		else
			square('|', ' ', '|', x);
		ft_putchar('\n');
		size++;
	}
}
/*
#include<stdlib.h>
int main(int ac, char **av)
{
	if(ac == 3)
	{
		int	x
		int	y;

		rush(atoi(av[1]),atoi(av[2]));
	}
	else
		return (0);
}*/
