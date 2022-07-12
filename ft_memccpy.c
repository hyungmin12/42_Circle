/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:54:27 by hyyoo             #+#    #+#             */
/*   Updated: 2022/07/12 23:12:51 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*tmp_dst;
	const unsigned char	*tmp_src;
	size_t				i;

	i = 0;
	tmp_dst = (unsigned char *)dst;
	tmp_src = (const unsigned char *)src;
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		if (tmp_dst[i] == (unsigned char)c)
			return (tmp_dst + 1 + i);
		i++;
	}
	return (0);
}
