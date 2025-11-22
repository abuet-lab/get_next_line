/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuet <abuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:37:36 by abuet             #+#    #+#             */
/*   Updated: 2025/11/22 19:03:00 by abuet            ###   ########.fr       */
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

static char *return_tab(char *tab, int i)
{
	char *return_tab;
	size_t size_tab;

	size_tab = search_new_line(tab);
	return_tab = malloc((size_tab + 2)* sizeof(char));
	if (!return_tab)
		return(NULL);
	ft_strlcpy(return_tab, tab, size_tab + 1);
	if (i == 1)
	{
	 	free(tab);
	 	tab = NULL;
	}
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
	size_t			bytes_read;
	static char		*final_tab;
	static size_t	size_malloc = 0;

	if (size_malloc == 0)
	{
		final_tab = malloc(1);
		if (!final_tab)
			return (NULL);
		final_tab[0] = '\0';
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		size_malloc += bytes_read;
		final_tab = ft_copy(buffer, final_tab, size_malloc);
		if (search_new_line(final_tab) != 0 )
			return(free(buffer), size_malloc -= search_new_line(final_tab),
			 return_tab(final_tab, 0));
	}
	if (bytes_read == 0 && ((search_new_line(final_tab) - 1) == size_malloc))
		return(free(buffer), return_tab(final_tab, 1));
	if (search_new_line(final_tab) != 0)
		return(free(buffer), return_tab(final_tab, 0));
	return (NULL);
}
