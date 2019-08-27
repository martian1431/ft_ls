/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:09:38 by pmalope           #+#    #+#             */
/*   Updated: 2019/08/27 14:52:03 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_access(t_stat *elem)
{
	ft_putchar((S_ISFIFO(elem->st_mode)) ? 'p' : '\0');
	ft_putchar((S_ISCHR(elem->st_mode)) ? 'c' : '\0');
	ft_putchar((S_ISDIR(elem->st_mode)) ? 'd' : '\0');
	ft_putchar((S_ISBLK(elem->st_mode)) ? 'b' : '\0');
	ft_putchar((S_ISREG(elem->st_mode)) ? '-' : '\0');
	ft_putchar((S_ISLNK(elem->st_mode)) ? 'l' : '\0');
	ft_putchar((S_ISSOCK(elem->st_mode)) ? 's' : '\0');
	ft_putchar((elem->st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((elem->st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((elem->st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((elem->st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((elem->st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((elem->st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((elem->st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((elem->st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((elem->st_mode & S_IXOTH) ? 'x' : '-');
	ft_putstr("  ");
}

void	ft_print_int(int nlink, int spacemax)
{
	int		n;
	char	*ptr;

	ptr = ft_itoa(nlink);
	n = spacemax - (int)ft_strlen(ptr);
	while (n-- > 0)
		ft_putchar(' ');
	ft_putnbr(nlink);
	free(ptr);
	ft_putstr(" ");
}

void	ft_print_str(char *str, int spacemax)
{
	int		n;

	n = spacemax - (int)ft_strlen(str);
	ft_putstr(str);
	while (n-- > 0)
		ft_putchar(' ');
	ft_putstr("  ");
}
