/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 08:48:37 by pmalope           #+#    #+#             */
/*   Updated: 2019/06/13 08:34:45 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*ptr_d;

	ptr_d = (char *)dst;
	while (n > 0)
	{
		if (*(unsigned char *)src != (unsigned char)c)
		{
			*ptr_d = *(unsigned char *)src;
			ptr_d++;
			src++;
		}
		else
		{
			*ptr_d = *(unsigned char *)src;
			ptr_d++;
			src++;
			return (ptr_d);
		}
		n--;
	}
	return (NULL);
}
