/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:12:46 by hyyoo             #+#    #+#             */
/*   Updated: 2022/07/18 17:23:10 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*now;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		now = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = now;
	}
	*lst = NULL;
}
