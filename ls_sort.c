/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:10:32 by pmalope           #+#    #+#             */
/*   Updated: 2019/08/27 14:56:36 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	void	ft_reversesort(t_stat **list)
{
	t_stat	*p;
	t_stat	*q;
	t_stat	*r;

	p = *list;
	q = NULL;
	r = NULL;
	while (p)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	*list = q;
}

static	void	ft_cpy_buf(t_stat **src, t_stat *cpy)
{
	(*src)->name = cpy->name;
	(*src)->path = cpy->path;
	(*src)->date = cpy->date;
	(*src)->st_mode = cpy->st_mode;
	(*src)->st_nlink = cpy->st_nlink;
	(*src)->st_uid = cpy->st_uid;
	(*src)->st_gid = cpy->st_gid;
	(*src)->st_size = cpy->st_size;
	(*src)->st_blocks = cpy->st_blocks;
}

static	void	ft_swap_buf(t_stat **a, t_stat **b)
{
	t_stat	tmp;

	tmp = **a;
	ft_cpy_buf(a, *b);
	ft_cpy_buf(b, &tmp);
}

static	void	ft_sort(t_stat **list, int (*cmp)(t_stat *elem1, \
			t_stat *elem2))
{
	t_stat	*a;
	t_stat	*b;

	a = *list;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (cmp(a, b) > 0)
				ft_swap_buf(&a, &b);
			b = b->next;
		}
		a = a->next;
	}
}

t_stat			*ft_sort_list(t_stat *list, t_option arg)
{
	t_stat	*temp;

	if (!list)
		return (NULL);
	temp = list;
	ft_sort(&temp, ft_cmp_alpha);
	(arg.t == 1) ? ft_sort(&temp, ft_cmp_time) : NULL;
	arg.r == 1 ? ft_reversesort(&temp) : NULL;
	return (temp);
}
