/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:26:37 by pmalope           #+#    #+#             */
/*   Updated: 2019/06/18 13:49:41 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		sign;
	int		tmp;

	sign = 1;
	tmp = 0;
	if (ft_strlen(str) >= 19 && ft_strcmp("9223372036854775807", str) < 0)
		return (-1);
	if (ft_strlen(str) >= 20 && ft_strcmp("-9223372036854775807", str) < 0)
		return (0);
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		tmp = tmp * 10 + *str - '0';
		str++;
	}
	return (tmp * sign);
}
