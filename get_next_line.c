/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:37:36 by abuet             #+#    #+#             */
/*   Updated: 2025/11/25 13:48:45 by antoinebuet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t search_new_line(char *tab)
{
	size_t	i;

	i = 0;
	if (!tab[i])
		return(0);
	while (tab[i])
	{
		if (tab[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

static char *return_tab(char *tab, size_t size_malloc)
{
	char *return_tab;
	size_t size_tab;

	size_tab = search_new_line(tab);
	return_tab = malloc((size_tab + 2)* sizeof(char));
	if (!return_tab)
		return(NULL);
	ft_strlcpy(return_tab, tab, size_tab + 1);
	free(tab);
	tab = NULL;
	size_malloc -= size_tab;
	tab = malloc((size_malloc + 1) * sizeof(char));
	if(!tab)
		return(NULL);
	ft_strlcpy(tab, return_tab + size_tab, size_malloc + 1);
	return_tab[size_tab] = '\0';
	return (return_tab);
}
static char *ft_copy(char *buffer, char *final_tab, size_t size_malloc)
{
	char *temp;
	temp = malloc((size_malloc + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, final_tab, size_malloc);
	ft_concat(temp, buffer, size_malloc);
	free(final_tab);
	final_tab = NULL;
	return (temp);
}

char *get_next_line(int fd)
{
	char			*buffer;
	size_t			bt_rd;
	static char		*final_tab;
	static size_t	size_malloc = 0;

	if (size_malloc == 0)
	{
		final_tab = malloc(1);
		if (!final_tab)
			return (NULL);
		final_tab[0] = '\0';
	}
	buffer = malloc((BUF_SZ + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (((bt_rd = read(fd, buffer, BUF_SZ)) > 0))
	{
		buffer[bt_rd] = '\0';
		size_malloc += bt_rd;
		final_tab = ft_copy(buffer, final_tab,2 size_malloc);
		if ((search_new_line(final_tab) != 0))
			break;
	}
	if (bt_rd < 0)
		return (NULL);
	if (bt_rd == 0 && search_new_line(final_tab) == 0)
		return(free(buffer), final_tab);
	return(free(buffer), return_tab(final_tab, size_malloc));
}
