/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:11:22 by pmalope           #+#    #+#             */
/*   Updated: 2019/08/20 07:24:12 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_check_opt(char c, char *str)
{
	int		i;

	if (str == NULL || c == '\0')
		return (0);
	i = -1;
	while (str[++i])
		if (c == str[i])
			return (1);
	return (0);
}

int		ft_symlnk(t_stat *buf)
{
	int		len;
	char	filelink[64];

	if (S_ISLNK(buf->st_mode))
	{
		ft_putstr(buf->name);
		ft_putstr(" -> ");
		len = (int )readlink(buf->path, filelink, 64);
		filelink[len] = '\0';
		ft_putstr(filelink);
		return (1);
	}
	return (0);
}
