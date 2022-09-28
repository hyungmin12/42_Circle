/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 06:37:27 by hyyoo             #+#    #+#             */
/*   Updated: 2022/06/06 06:37:51 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	p_me(unsigned long long number_address, int depth);
void	p_res(long long num);
void	p_s(unsigned char *six, int size);
void	what_the(int bigsmall, unsigned char *n_add);

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char				*n_add;
	unsigned int				idx;
	int							jex;
	int							bigsmall;

	idx = 0;
	while (idx < size)
	{
		n_add = (unsigned char *)addr + idx;
		p_me ((unsigned long long)n_add, 0);
		write (1, ":", 1);
		if (size - idx > 15)
			bigsmall = 16;
		else
			bigsmall = size % 16;
		p_s (n_add, bigsmall);
		write(1, " ", 1);
		jex = 0;
		what_the(bigsmall, n_add);
		idx += 16;
		write (1, "\n", 1);
	}
	return (addr);
}

void	p_res(long long num)
{
	char	result;

	if (num < 10)
		result = (int)num + '0';
	else if (num >= 10)
		result = (int)num - 10 + 'a';
	write (1, &result, 1);
}

void	p_me(unsigned long long number_address, int deep)
{
	unsigned long long	num;

	num = number_address % 16;
	if (deep == 15)
	{
		p_res(num);
		return ;
	}
	p_me(number_address / 16, deep + 1);
	p_res(num);
}

void	what_the(int bigsmall, unsigned char *n_add)
{
	int	jex;

	jex = 0;
	while (jex < bigsmall)
	{
		if (n_add[jex] >= 32 && n_add[jex] <= 126)
			write(1, &n_add[jex], 1);
		else
			write(1, ".", 1);
		jex++;
	}
}

void	p_s(unsigned char *six, int size)
{
	int				idx;
	int				result[2];
	char			*gw;

	gw = "0123456789abcdef";
	idx = 0;
	while (idx < size)
	{
		if (idx % 2 == 0)
			write(1, " ", 1);
		result[0] = six[idx] / 16;
		result[1] = six[idx] % 16;
		write (1, &gw[result[0]], 1);
		write (1, &gw[result[1]], 1);
		idx++ ;
	}
	while (size < 16)
	{
		if (size % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		size++;
	}
}
