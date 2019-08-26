/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 21:41:58 by pmalope           #+#    #+#             */
/*   Updated: 2019/06/13 09:12:05 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *tmp;

	tmp = NULL;
	if ((char)c == '\0')
	{
		tmp = (char *)s + ft_strlen(s);
		return (tmp);
	}
	while (*s)
	{
		if (*s == (char)c)
			tmp = (char *)s;
		s++;
	}
	return (tmp);
}
