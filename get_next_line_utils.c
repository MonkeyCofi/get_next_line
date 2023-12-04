/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwubuntu <uwubuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 01:12:44 by uwubuntu          #+#    #+#             */
/*   Updated: 2023/12/04 20:02:39 by uwubuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	if (!str)
		return (0);
	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	if (!(unsigned char)c)
		return ((char *)&s[ft_strlen((char *)s)]);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

size_t	get_line_len(char *buffer)
{
	size_t	line_len;

	line_len = 0;
	if (!buffer)
		return (line_len);
	while (buffer[line_len] != '\n' && buffer[line_len])
		line_len++;
	if (buffer[line_len] == '\n' && buffer[line_len])
		line_len++;
	return (line_len);
}