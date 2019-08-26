/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 12:19:02 by pmalope           #+#    #+#             */
/*   Updated: 2019/06/18 13:24:19 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_nbwords(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (*(s + i))
	{
		while (*(s + i) == c)
			i++;
		if (*(s + i))
			words++;
		while (*(s + i) && *(s + i) != c)
			i++;
	}
	return (words);
}

static	void	ft_split(char **tab, char const *str, char c)
{
	int		i;
	int		words;
	size_t	index;
	size_t	len;

	i = 0;
	index = 0;
	len = 0;
	words = ft_nbwords(str, c);
	while (words - i)
	{
		while (str && *(str + index) == c)
			index++;
		while (str && *(str + index + len) && *(str + index + len) != c)
			len++;
		tab[i] = ft_strsub(str, index, len);
		index += len;
		len = 0;
		i++;
	}
	tab[i] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;

	tab = NULL;
	if (!s)
		return (tab);
	tab = (char **)malloc(sizeof(char *) * (ft_nbwords((char *)s, c) + 1));
	if (!tab)
		return (NULL);
	ft_split(tab, s, c);
	return (tab);
}
