/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:45:21 by hyyoo             #+#    #+#             */
/*   Updated: 2022/07/12 23:49:03 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr_s;
	unsigned char		value_c;

	ptr_s = (const unsigned char *)s;
	value_c = (unsigned char)c;
	while (n--)
	{
		if (*ptr_s == value_c)
			return ((void *)ptr_s);
		ptr_s++;
	}
	return (0);
}
