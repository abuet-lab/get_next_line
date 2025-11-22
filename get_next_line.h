/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuet <abuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:37:40 by abuet             #+#    #+#             */
/*   Updated: 2025/11/22 15:59:59 by abuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>

# ifndef  BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_concat(char *s1, char *s2, size_t size);
int	ft_search_end_line(char *final_tab);


#endif