/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:03:20 by uwubuntu          #+#    #+#             */
/*   Updated: 2023/12/06 14:02:57 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/* Temp headers */
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
/* Temp headers */

# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);
size_t	get_line_len(char *buffer);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	*malloc_buf(char **pbfr, size_t mal_size);

#endif