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
	struct stat	stat_buf;

	buf = (t_stat *)malloc(sizeof(t_stat));
	buf->name = ft_strdup(name);
	buf->path = ft_strjoin(path, name);
	if (lstat(buf->path, &stat_buf) == -1)
	{
		ft_error("ft_ls: ", buf->name, 1);
		return (NULL);
	}
	buf->st_mode = stat_buf.st_mode;
	buf->st_nlink = stat_buf.st_nlink;
	buf->st_uid = stat_buf.st_uid;
	buf->st_gid = stat_buf.st_gid;
	buf->st_size = stat_buf.st_size;
	buf->st_blocks = stat_buf.st_blocks;
	buf->date = stat_buf.st_mtime;
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

void		ft_list_add_files(t_stat **lst, char *name, char *path)
{
	t_stat	*temp;

	temp = *lst;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = ft_listnew(name, path);
	}
	else
		*lst = ft_listnew(name, path);
}
