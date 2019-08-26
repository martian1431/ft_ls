/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 09:20:33 by pmalope           #+#    #+#             */
/*   Updated: 2019/06/13 15:45:31 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*elem;
	t_list	*next;

	elem = *alst;
	while (elem)
	{
		del(elem->content, elem->content_size);
		next = elem->next;
		free(elem);
		elem = next;
	}
	*alst = NULL;
}
