/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:05:28 by pmalope           #+#    #+#             */
/*   Updated: 2019/06/05 10:31:30 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_add(t_list *elem)
{
	int i;

	i = 0;
	while (((unsigned char)elem->content)[i])
	{
		((unsigned char *)elem->content[i]) += 32;
		i++;
	}
}
