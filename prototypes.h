/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:09:49 by pmalope           #+#    #+#             */
/*   Updated: 2019/08/28 07:35:08 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "ft_ls.h"

void		free_memory(t_stat *files);
void		free_lists(t_list *list);
void		ft_error_opt(char opt);
void		ft_error(char *name, char *error, int ex);
void		ft_open_dir(t_option arg, t_list *path, int nbr_dir);
void		ft_display_file(t_option opt, t_stat *files, int fileordir);
int			ft_list_add(t_stat **files, struct dirent *file, char *path);
void		ft_list_add_files(t_stat **lst, char *name, char *path);
int			ft_symlnk(t_stat *buf);
t_stat		*ft_sort_list(t_stat *list, t_option arg);
int			ft_compare_alpha(t_stat *elem1, t_stat *elem2);
int			ft_compare_time(t_stat *elem1, t_stat *elem2);
void		ft_recursion(t_option arg, t_stat *files);
void		ft_simple(t_option arg, t_stat *files);
void		ft_ls_long(t_option arg, t_stat *files, int fileordir);
t_size		ft_get_size(t_option arg, t_stat *files);
void		ft_print_access(t_stat *elem);
void		ft_print_int(int nlink, int spacemax);
void		ft_print_str(char *str, int spacemax);
void		ft_print_file(t_stat *files, t_stat *dirlist, t_option opt, int n);
#endif
