/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:10:17 by pmalope           #+#    #+#             */
/*   Updated: 2019/08/19 13:07:56 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_get_size_quick(t_size *size, t_stat *buf)
{
    char    *ptr;
    char    *ptr2;
    
    ptr2 = ft_itoa((int )buf->st_nlink);
    ptr = ft_itoa((int )buf->st_size);
	size->linkspace = (int)ft_strlen(ptr2) > \
		size->linkspace ? (int)ft_strlen(ptr2) \
		: size->linkspace;
	size->size = (int)ft_strlen(ptr) > size->size ? \
		(int)ft_strlen(ptr) : size->size;
	size->total += buf->st_blocks;
    free(ptr);
    free(ptr2);
}

t_size	ft_get_size(t_option arg, t_stat *files)
{
	t_stat		*temp;
	t_size		size;

	size = (t_size){0, 0, 0, 0, 0};
	temp = files;
	while (temp)
	{
		if (!(arg.a == OFF && temp->name[0] == '.'))
			ft_get_size_quick(&size, temp);
		temp = temp->next;
	}
	return (size);
}
