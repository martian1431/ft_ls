/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:23:44 by pmalope           #+#    #+#             */
/*   Updated: 2019/08/27 14:49:01 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_display_file(t_option opt, t_stat *files, int fileordir)
{
	t_stat	*temp;

	temp = files;
	temp = ft_sort_list(temp, opt);
	if (opt.l == ON)
		ft_ls_long(opt, temp, fileordir);
	else
		ft_simple(opt, temp);
	opt.upper_r == ON ? ft_recursion(opt, temp) : NULL;
}

void			ft_simple(t_option arg, t_stat *files)
{
	t_stat	*temp;

	temp = files;
	while (temp)
	{
		if (!(arg.a == OFF && temp->name[0] == '.'))
			ft_putendl(temp->name);
		temp = temp->next;
	}
}

static	int		ft_display_date(time_t date, t_stat *buf)
{
	int		res;
	char	*str1;
	char	*str2;
	time_t	actual_time;

	actual_time = time(0);
	str1 = ctime(&date);
	if ((actual_time - 15778463) > date || actual_time < date)
	{
		str2 = ft_strnew(6);
		str2 = ft_strsub(str1, 20, 4);
		str1 = ft_strsub(str1, 4, 6);
		str1 = ft_strjoin(str1, "  ");
		str1 = ft_strjoin(str1, str2);
		free(str2);
	}
	else
		str1 = ft_strsub(str1, 4, 12);
	str1[12] = '\0';
	ft_putstr(str1);
	ft_putchar(' ');
	res = ft_symlnk(buf);
	free(str1);
	return (res);
}

static	void	ft_display_lformat(t_stat *temp, t_size size)
{
	ft_print_access(temp);
	ft_print_int(temp->st_nlink, size.linkspace);
	if (getpwuid(temp->st_uid))
		ft_print_str(getpwuid(temp->st_uid)->pw_name, size.userspace);
	else
		ft_print_str(ft_itoa(temp->st_uid), size.userspace);
	if (getgrgid(temp->st_gid))
		ft_print_str(getgrgid(temp->st_gid)->gr_name, size.groupspace);
	else
		ft_print_str(ft_itoa(temp->st_gid), size.groupspace);
	if (S_ISCHR(temp->st_mode) || S_ISBLK(temp->st_mode))
		ft_print_int((int)temp->st_size, size.size);
	ft_print_int((int)temp->st_size, size.size);
	if (ft_display_date(temp->date, temp))
		ft_putchar('\n');
	else
		ft_putendl(temp->name);
}

void			ft_ls_long(t_option arg, t_stat *files, int fileordir)
{
	t_stat		*temp;
	t_size		size;

	temp = files;
	size = ft_get_size(arg, files);
	if (fileordir)
	{
		ft_putstr("total ");
		ft_putnbr(size.total);
		ft_putchar('\n');
	}
	while (temp)
	{
		if (!(arg.a == 0 && temp->name[0] == '.'))
			ft_display_lformat(temp, size);
		temp = temp->next;
	}
}
