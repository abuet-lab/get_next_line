/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:37:32 by abuet             #+#    #+#             */
/*   Updated: 2025/12/05 20:39:06 by antoinebuet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char *ft_strjoin(char *s1,char *s2)
{
	char *join;
	int i;
	int j;

	if (!s1 || !s2 )
		return (NULL);
	join = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	return (join);
}

int search_new_line(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}
