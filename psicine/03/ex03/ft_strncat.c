/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:29:39 by hyyoo             #+#    #+#             */
/*   Updated: 2022/05/26 18:57:37 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	ptr = dest;
	while (*ptr)
	{
		ptr++;
	}
	while (*src && i < nb)
	{
		*ptr = *src;
		ptr++;
		src++;
		i++;
	}
	*ptr = 0;
	return (dest);
}
