/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 08:50:16 by pmalope           #+#    #+#             */
/*   Updated: 2019/06/13 12:06:14 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp_dst;
	char	*tmp_src;

	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	if (tmp_dst == tmp_src)
		return (tmp_dst);
	if ((tmp_dst <= tmp_src) || (tmp_dst >= (tmp_src + len)))
	{
		while ((len--) > 0)
			*(tmp_dst++) = *(tmp_src++);
	}
	else
	{
		tmp_src += len - 1;
		tmp_dst += len - 1;
		while (len-- > 0)
			*(tmp_dst--) = *(tmp_src--);
	}
	return (dst);
}
