/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:37:40 by abuet             #+#    #+#             */
/*   Updated: 2025/11/30 21:20:58 by antoinebuet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>

# ifndef BUF_SZ
#  define BUF_SZ 20000000
# endif

char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_concat(char *s1, char *s2, size_t size);
int		ft_search_end_line(char *final_tab);
size_t	ft_strlen(const char *s);
char	*ft_initialize(char *final_tab);

#endif