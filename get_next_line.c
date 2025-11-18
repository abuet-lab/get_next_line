/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuet <abuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:37:36 by abuet             #+#    #+#             */
/*   Updated: 2025/11/18 19:08:48 by abuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_cut(char *final_tab, size_t size_malloc)
{
	char *return_tab;
	int size;

	size = search_new_line(final_tab);
	return_tab = malloc((size + 2) * sizeof(char));
	ft_strlcpy(return_tab, final_tab, size_malloc);
	return(return_tab);
}
static int search_new_line(char *tab)
{
	int i;

	i = 0;
	while (tab[i] == '\n' || tab[i] == '\0')
		i++;
	return (i);
}

static char *ft_copy(char *buffer, char *final_tab, size_t size_malloc)
{
	char *temp;
	temp = malloc((size_malloc + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, final_tab, size_malloc);
	ft_concat(temp, buffer, size_malloc);
	return (temp);
}

char *get_next_line(int fd)
{
	char			*buffer;
	size_t			bytes_read;
	static char		*final_tab;
	static size_t	size_malloc = 0;
	static int		counter = 1;
	char 			*return_tab;

	if (counter == 1)
		final_tab = malloc(2);
	
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
	buffer[bytes_read + 1] = '\0';
	size_malloc += bytes_read;
	final_tab = ft_copy(buffer, final_tab, size_malloc);
	}
	
	free(buffer);
	return (ft_cut(final_tab, size_malloc));		
}
