/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:10:54 by pmalope           #+#    #+#             */
/*   Updated: 2019/08/19 11:08:32 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "ft_ls.h"

typedef struct			s_opttion
{
	int		l;
	int		upper_r;
	int		a;
	int		r;
	int		t;
}						t_option;

typedef struct			s_stat
{
	char			*name;
	char			*path;
	time_t			date;
	mode_t			st_mode;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	off_t			st_size;
	quad_t			st_blocks;
	struct s_stat	*next;
}						t_stat;

typedef struct			s_size
{
	int		total;
	int		size;
	int		groupspace;
	int		userspace;
	int		linkspace;
}						t_size;
#endif
