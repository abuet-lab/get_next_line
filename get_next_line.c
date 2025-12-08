/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:37:36 by abuet             #+#    #+#             */
/*   Updated: 2025/12/06 22:11:52 by antoinebuet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_remove_line(char *tab)
{
	char *new_tab;
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i] && tab[i] != '\n')
		i++;
	if (!tab)
		return (free(tab), NULL);
	new_tab = malloc((ft_strlen(tab) - i + 1) * sizeof(char));
	if (!new_tab)
		return(free(tab), NULL);
	while(tab[i++])
	{
		new_tab[j] = tab[i];
		j++;
	}
	new_tab[j] = '\0';
	return(free(tab), new_tab);
}
static char *ft_print_tab(char *tab)
{
	char *print;
	int	i;

	i = 0;
	if (tab[0] == 0)
		return (NULL);
	print = malloc((search_new_line(tab) + 2) * sizeof(char));
	if (!print)
		return (NULL);
	while (tab[i] != '\n' && tab[i])
	{
		print[i] = tab[i];
		i++;
	}
	if (tab[i] == '\n')
	{
		print[i] = '\n';
		i++;
	}
	print[i] = '\0';
	return (print);
}

static char *ft_alloc_tab(char *stat,int fd)
{
	char *buffer;
	ssize_t bytes_read;

	bytes_read = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return(NULL);
	if (!stat)
	{
		stat = malloc(1);
		if (!stat)
			return (NULL);
		stat[0] = '\0'; 
	}
	while (search_new_line(stat) == 0 && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return(free(buffer), free(stat), NULL);
		buffer[bytes_read] = '\0';
		stat = ft_strjoin(stat, buffer);
	}
	return (stat);
}

char	*get_next_line(int fd)
{
	static char  *stat;
	char *print;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	stat = ft_alloc_tab(stat, fd);
	if (!stat)
		return (NULL);
	print = ft_print_tab(stat);
	stat = ft_remove_line(stat);
	return (print);
}
