/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:08:23 by pmalope           #+#    #+#             */
/*   Updated: 2019/08/19 10:10:29 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_stat		*ft_listnew(char *name, char *path)
{
	t_stat		*buf;
	struct stat	fstat;

	buf = (t_stat *)malloc(sizeof(t_stat));
	buf->name = ft_strdup(name);
	buf->path = ft_strjoin(path, name);
	if (lstat(buf->path, &fstat) == -1)
	{
		ft_error("ft_ls: ", buf->name, 1);
		return (NULL);
	}
	buf->st_mode = fstat.st_mode;
	buf->st_nlink = fstat.st_nlink;
	buf->st_uid = fstat.st_uid;
	buf->st_gid = fstat.st_gid;
	buf->st_size = fstat.st_size;
	buf->st_blocks = fstat.st_blocks;
	buf->date = fstat.st_mtime;
	buf->next = NULL;
	return (buf);
}

int			ft_list_add(t_stat **files, struct dirent *file, char *path)
{
	t_stat	*list;

	list = *files;
	if (!file)
		return (0);
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_listnew(file->d_name, path);
	}
	else
		*files = ft_listnew(file->d_name, path);
	return (1);
}

void		ft_list_getfiles(t_stat **files, char *name, char *path)
{
	t_stat	*list;

	list = *files;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_listnew(name, path);
	}
	else
		*files = ft_listnew(name, path);
}
