/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:11:22 by pmalope           #+#    #+#             */
/*   Updated: 2019/08/27 14:49:46 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error_opt(char opt)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(opt, 2);
	ft_putstr_fd("\nusage: ft_ls [-lRrat] [file ...]\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_error(char *name, char *error, int ex)
{
	ft_putstr_fd(name, 2);
	perror(error);
	if (ex)
		exit(EXIT_FAILURE);
}

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

int		ft_symlnk(t_stat *buf)
{
	int		len;
	char	filelink[64];

	if (S_ISLNK(buf->st_mode))
	{
		ft_putstr(buf->name);
		ft_putstr(" -> ");
		len = (int)readlink(buf->path, filelink, 64);
		filelink[len] = '\0';
		ft_putstr(filelink);
		return (1);
	}
	return (0);
}
