/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 08:46:35 by pmalope           #+#    #+#             */
/*   Updated: 2019/08/27 13:41:50 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_memory(t_stat *files)
{
	t_stat *next;
	
	while (files)
	{
		next = files->next;
		free(files->name);
		free(files->path);
		free(files);
		files = next;
	}
}

void	free_lists(t_list *list)
{
	t_list	*next;
	while (list)
	{
		next = list->next;
		free(list->content);
		free(list);
		list = next;
	}
}
