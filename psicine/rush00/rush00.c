/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebikim <yebikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:55:08 by yebikim           #+#    #+#             */
/*   Updated: 2022/10/02 22:47:38 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush00_ver(char start, char middle, char end, int x)
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
	if (x > 2147483647 || y > 2147483647)
		return ;
	while (size <= y)
	{
		if (size == 1)
			rush00_ver('o', '-', 'o', x);
		else if (size == y)
			rush00_ver('o', '-', 'o', x);
		else
			rush00_ver('|', ' ', '|', x);
		ft_putchar('\n');
		size++;
	}
}
