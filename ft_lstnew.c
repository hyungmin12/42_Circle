/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:46:21 by hyyoo             #+#    #+#             */
/*   Updated: 2022/07/18 17:38:43 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (!(ret))
		return (NULL);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}
