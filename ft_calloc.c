/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:23:26 by hyyoo             #+#    #+#             */
/*   Updated: 2022/08/03 16:53:35 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*zero;

	if (!(zero = (char *)malloc(sizeof(*zero) * count * size)))
		return (NULL);
	ft_memset(zero, 0, count * size);
	return (zero);
}
