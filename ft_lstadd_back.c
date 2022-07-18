/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:23:27 by hyyoo             #+#    #+#             */
/*   Updated: 2022/07/18 17:39:13 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_list;

	last_list = *lst;
	if (!lst || !new)
		return ;
	else if (*lst && !new)
	{
		*lst = new;
		return ;
	}
	while((*lst)->next)
	{
		*lst = (*lst)->next;
	}
	(*lst)->next = new;
	*lst = last_list;
}
