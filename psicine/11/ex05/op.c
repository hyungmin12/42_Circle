/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:26:26 by hyyoo             #+#    #+#             */
/*   Updated: 2022/10/17 14:27:34 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_head.h"

long	add(long a, long b)
{
	return (a + b);
}

long	moin(long a, long b)
{
	return (a - b);
}

long	x_this(long a, long b)
{
	return (a * b);
}

long	div(long a, long b)
{
	if (b == 0)
		return (-1);
	return (a / b);
}

long	mod(long a, long b)
{
	if (b == 0)
		return (-1);
	return (a % b);
}
