/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuet <abuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:37:36 by abuet             #+#    #+#             */
/*   Updated: 2025/11/11 18:17:20 by abuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

const int search_new_line(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == "\n" || buffer[i] == "\0")
			return(i);
		i++;
	}
	return (-1);
}

void	ft_copy(char *buffer, char *final_tab, size_t size_malloc)
{
	char *temp;

	temp = malloc(size_malloc * sizeof(char));
	if (!temp)
		return(NULL);
	ft_strlcpy()
	
}

char *get_next_line(int fd)
{
	char *buffer;
	size_t bytes_read;
	char *final_tab;
	size_t count;

	count = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	while (bytes_read = read(fd, buffer, BUFFER_SIZE) > 0)
	{
		count += bytes_read;
		ft_copy(buffer, final_tab, bytes_read);
		
		
	}
	free(buffer);
		
	
}