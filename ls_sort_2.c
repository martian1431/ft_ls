/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:10:45 by pmalope           #+#    #+#             */
/*   Updated: 2019/08/19 07:10:48 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_cmp_alpha(t_stat *elem1, t_stat *elem2)
{
	return (ft_strcmp(elem1->name, elem2->name));
}

int		ft_cmp_time(t_stat *elem1, t_stat *elem2)
{
	return (elem1->date < elem2->date);
}
