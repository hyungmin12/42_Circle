/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:12:46 by hyyoo             #+#    #+#             */
/*   Updated: 2022/08/03 16:45:55 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*last_lst;

	last_lst = *lst;
	if (lst != NULL || *lst != NULL)
	{
		while (*lst)
		{
			*lst = last_lst->next;
			del(last_lst->content);
			free(last_lst);
			last_lst = *lst;
		}
	}
}
