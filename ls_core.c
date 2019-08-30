/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:09:03 by pmalope           #+#    #+#             */
/*   Updated: 2019/08/28 14:56:52 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	void	ft_ls_dir2(t_option opt, t_stat *dirlist, int nb_dir)
{
	DIR			*dir;
	t_stat		*files;
	char		*tmp;

	files = NULL;
	tmp = NULL;
	while (dirlist)
	{
		dir = opendir(dirlist->name);
		tmp = ft_strjoin(dirlist->path, "/");
		while (ft_list_add(&files, readdir(dir), tmp) != 0)
			;
		closedir(dir);
		ft_print_file(files, dirlist, opt, nb_dir);
		dirlist = dirlist->next;
	}
	free(tmp);
	free_memory(files);
}

static	void	ft_ls_dir(t_option opt, t_list *path, int nb_dir)
{
	t_list		*tmp_path;
	t_stat		*dir_list;

	tmp_path = path;
	dir_list = NULL;
	while (tmp_path)
	{
		ft_list_add_files(&dir_list, tmp_path->content, "");
		tmp_path = tmp_path->next;
	}
	dir_list = ft_sort_list(dir_list, opt);
	ft_ls_dir2(opt, dir_list, nb_dir);
	free_lists(path);
	free_memory(dir_list);
}

void			ft_ls_file(t_option opt, t_list *path)
{
	t_list		*tmp_path;
	t_stat		*files;

	tmp_path = path;
	files = NULL;
	opt.a = ON;
	while (tmp_path)
	{
		ft_list_add_files(&files, tmp_path->content, "");
		tmp_path = tmp_path->next;
	}
	if (files)
		ft_display_file(opt, files, 0);
}

void			ft_open_dir(t_option opt, t_list *path, int nbr_dir)
{
	DIR		*dir;
	t_list	*file;
	t_list	*directory;
	t_list	*temp;

	file = NULL;
	directory = NULL;
	temp = path;
	while (temp)
	{
		if ((dir = opendir(temp->content)) == NULL)
			errno != ENOTDIR ? ft_error("ft_ls: ", \
			temp->content, 0) : ft_lstpushback(&file, temp->content, \
			temp->content_size);
		else
		{
			ft_lstpushback(&directory, temp->content, temp->content_size);
			if (closedir(dir) == -1)
				ft_error("ft_ls:", temp->content, 0);
		}
		temp = temp->next;
	}
	file ? ft_ls_file(opt, file) : NULL;
	file && directory ? ft_putchar('\n') : NULL;
	directory ? ft_ls_dir(opt, directory, nbr_dir) : NULL;
}
