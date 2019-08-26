/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:25:08 by pmalope           #+#    #+#             */
/*   Updated: 2019/06/18 13:29:10 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	start;
	size_t	end;
	char	*str;

	start = 0;
	end = 0;
	if (!s)
		return (NULL);
	else
	{
		len = ft_strlen(s);
		while (*(s + start) && ft_isspace(*(s + start)))
			start++;
		while (s && end < len && ft_isspace(*(s + len - 1 - end)))
			end++;
		if ((int)(len - end - start) < 0)
		{
			str = ft_strsub(s, start, 0);
			return (str);
		}
	}
	str = ft_strsub(s, start, len - end - start);
	return (str);
}
