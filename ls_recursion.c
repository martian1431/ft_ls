/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:10:03 by pmalope           #+#    #+#             */
/*   Updated: 2019/08/19 07:10:05 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_do_recursion(t_option arg, char *path)
{
	t_stat		*files;
	DIR			*dir;

	files = NULL;
	ft_putchar('\n');
	ft_putstr(path);
	ft_putstr(":\n");
	if ((dir = opendir(path)) != NULL)
	{
		while (ft_list_add(&files, readdir(dir), \
					ft_strjoin(path, "/")) != 0)
			;
		closedir(dir);
		if (files)
			ft_display_file(arg, files, 1);
		files = NULL;
	}
	else
		ft_error("ft_ls: ", path, 0);
}

void	ft_recursion(t_option arg, t_stat *files)
{
	t_stat	*temp;

	temp = files;
	while (temp)
	{
		if (temp->name && temp->path && \
				S_ISDIR(temp->st_mode) && \
				ft_strcmp(".", temp->name) && \
				ft_strcmp("..", temp->name) && \
				!(arg.a == 0 && temp->name[0] == '.'))
			ft_do_recursion(arg, temp->path);
		temp = temp->next;
	}
}