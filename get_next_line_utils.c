/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:37:32 by abuet             #+#    #+#             */
/*   Updated: 2025/11/30 21:10:45 by antoinebuet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (src[size])
		size++;
	if (dstsize == 0)
		return (size);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (size);
}

void	ft_concat(char *s1, char *s2, size_t size)
{
	size_t	i;
	size_t	t;

	i = 0;
	t = 0;
	while (s1[i] && (t + i) < size)
		i++;
	while (s2[t] && (t + i) < size)
	{
		s1[i + t] = s2[t];
		t++;
	}
	s1[i + t] = '\0';
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_initialize(char *final_tab)
{
	final_tab = malloc(1);
	if (!final_tab)
		return (NULL);
	final_tab[0] = '\0';
	return (final_tab);
}
