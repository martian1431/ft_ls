/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:32:37 by pmalope           #+#    #+#             */
/*   Updated: 2019/06/13 15:44:07 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*node_item;

	if (lst)
	{
		node = f(lst);
		node_item = node;
		lst = lst->next;
		while (lst)
		{
			node_item->next = f(lst);
			node_item = node_item->next;
			lst = lst->next;
		}
		return (node);
	}
	return (NULL);
}
