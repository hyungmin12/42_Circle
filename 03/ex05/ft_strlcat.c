/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:34:57 by hyyoo             #+#    #+#             */
/*   Updated: 2022/05/25 19:35:00 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (*dest && (i < size))
	{
		dest++;
		i++;
	}
	while (*src && ((i + 1) < size))
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	if (i < size)
	{
		*dest = 0;
	}
	while (*src)
	{
		i++;
		src++;
	}
	return (i);
}
