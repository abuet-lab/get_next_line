/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuet <abuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:37:36 by abuet             #+#    #+#             */
/*   Updated: 2025/12/02 13:44:18 by abuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	search_new_line(char *tab)
{
	size_t	i;

	i = 0;
	if (!tab[i])
		return (0);
	while (tab[i])
	{
		if (tab[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

static char	*return_tab(char *tab)
{
	char	*return_tab;
	size_t	size_tab;

	size_tab = search_new_line(tab);
	return_tab = malloc((size_tab + 1) * sizeof(char));
	if (!return_tab)
		return (NULL);
	ft_strlcpy(return_tab, tab, size_tab + 1);
	return (return_tab);
}

static char	*ft_copy(char *buffer, char **final_tab)
{
	size_t	size_malloc;
	char	*temp;

	size_malloc = (ft_strlen(*final_tab) + ft_strlen(buffer));
	temp = malloc((size_malloc + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, *final_tab, ft_strlen(*final_tab) + 1);
	ft_concat(temp, buffer, size_malloc);
	free(*final_tab);
	*final_tab = NULL;
	return (temp);
}

static char	*clean_tab(char **final_tab)
{
	size_t	i;
	size_t	len;
	char	*new_tab;

	i = search_new_line(*final_tab);
	if (i == 0)
		return (*final_tab);
	len = ft_strlen(*final_tab + i);
	new_tab = malloc(len + 1);
	if (!new_tab)
		return (NULL);
	ft_strlcpy(new_tab, *final_tab + i, len + 1);
	free(*final_tab);
	*final_tab = NULL;
	return (new_tab);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	ssize_t			bt_rd;
	static char		*final_tab;
	char			*re_tab;

	bt_rd = 1;
	if (!final_tab)
		final_tab = ft_initialize(final_tab);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (search_new_line(final_tab) == 0 && bt_rd > 0)
	{
		bt_rd = read(fd, buffer, BUFFER_SIZE);
		if (bt_rd == -1)
			return(ft_free(&buffer, &final_tab), NULL);
		buffer[bt_rd] = '\0';
		final_tab = ft_copy(buffer, &final_tab);
	}
	if (final_tab[0] == '\0')
		return(ft_free(&buffer, &final_tab), NULL);
	if (bt_rd == 0 && search_new_line(final_tab) == 0)
	{
		re_tab = final_tab;
		final_tab = NULL;
		return (free(buffer), re_tab);
	}
	re_tab = return_tab(final_tab);
	final_tab = clean_tab(&final_tab);
	return (free(buffer), re_tab);
}
