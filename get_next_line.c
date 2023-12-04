/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwubuntu <uwubuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:44:06 by uwubuntu          #+#    #+#             */
/*   Updated: 2023/12/04 19:55:30 by uwubuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// fetch a line from the buffer
char	*line_fetch(char *buffer)
{
	char	*line;
	size_t	line_len;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	line_len = get_line_len(buffer);
	line = malloc(sizeof(char) * (line_len + 1));
	if (!line)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n' && buffer[i])
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_buf(char *buffer)
{
	char	*new_buf;
	size_t	remaining;
	size_t	i;

	remaining = 0;
	i = 0;
	while (buffer[remaining] && buffer[remaining] != '\n')
		remaining++;
	if (!buffer[remaining])
	{
		free(buffer);
		return (NULL);
	}
	new_buf = malloc(sizeof(char) * (ft_strlen(buffer) - remaining + 1));
	if (!new_buf)
		return (NULL);
	if (buffer[remaining] == '\n' && buffer[remaining])
		remaining++;
	while (buffer[remaining])
		new_buf[i++] = buffer[remaining++];
	new_buf[i] = '\0';
	free(buffer);
	return (new_buf);
}

char	*join_newbuf(char *old_buf, char *curr_buf)
{
	char	*new_buf;

	new_buf = ft_strjoin(old_buf, curr_buf);
	if (!new_buf)
		return (NULL);
	free(old_buf);
	return (new_buf);
}

char	*populate_buffer(int fd, char *buffer)
{
	char	*temp_buf;
	int		b_read;

	if (!buffer)
	{
		buffer = malloc(sizeof(char));
		if (!buffer)
			return (NULL);
		buffer[0] = 0;
	}
	b_read = 1;
	temp_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buf)
		return (NULL);
	while (b_read > 0 && !ft_strchr(buffer, '\n'))
	{
		b_read = read(fd, temp_buf, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(temp_buf);
			return (NULL);
		}
		temp_buf[b_read] = '\0';
		buffer = join_newbuf(buffer, temp_buf);
	}
	free(temp_buf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*remaining_buf;

	if (fd <= 0)
		return (NULL);
	buffer = populate_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = line_fetch(buffer);
	remaining_buf = update_buf(buffer);
	if (buffer)
		buffer = remaining_buf;
	return (line);
}

int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char *str;
	// str = get_next_line(fd);
	// printf("%s", str);
	// free(str);
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
		
}