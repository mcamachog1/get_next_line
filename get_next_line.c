/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:48:23 by macamach          #+#    #+#             */
/*   Updated: 2025/12/06 14:32:05 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	read_buffer(int fd, char *buffer, int *bytes_read)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if ((*bytes_read) <= 0)
		return (0);
	if (*bytes_read > 0)
		buffer[*bytes_read] = '\0';
	return (1);
}

char	*make_line(char *tail)
{
	char	*line;
	char	*pos;
	size_t	size;

	pos = ft_strchr(tail, BREAK_LINE);
	if (!pos)
		size = ft_strlen(tail);
	else
		size = pos - tail + 1;
	line = ft_calloc(size + 1, 1);
	if (!line)
		return (NULL);
	ft_strlcat(line, tail, size + 1);
	return (line);
}

char	*append_tail(char *tail, const char *buffer)
{
	size_t	size;
	char	*new_tail;

	size = ft_strlen(tail) + ft_strlen(buffer) + 1;
	new_tail = ft_calloc(size, 1);
	if (!new_tail)
		return (free(tail), NULL);
	if (tail)
		ft_strlcat(new_tail, tail, size);
	ft_strlcat(new_tail, buffer, size);
	free(tail);
	return (new_tail);
}

char	*trim_tail(char *tail)
{
	char	*new_tail;
	char	*pos;
	size_t	size;

	pos = ft_strchr(tail, BREAK_LINE);
	if (!pos)
		return (free(tail), NULL);
	else
	{
		pos++;
		size = ft_strlen(pos);
	}
	new_tail = ft_calloc(size + 1, 1);
	if (!new_tail)
		return (free(tail), NULL);
	ft_strlcat(new_tail, pos, size + 1);
	free(tail);
	if (ft_strlen(new_tail) == 0)
		return (free(new_tail), NULL);
	return (new_tail);
}

char	*get_next_line(int fd)
{
	static char	*tail;
	char		*current_line;
	char		*buffer;
	int			bytes_read;

	bytes_read = 0;
	current_line = NULL;
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buffer(fd, buffer, &bytes_read) && !ft_strlen(tail))
		return (free(buffer), NULL);
	while (bytes_read > 0 || ft_strlen(tail))
	{
		if (bytes_read > 0)
			tail = append_tail(tail, buffer);
		if (ft_strchr(tail, BREAK_LINE) || bytes_read == 0)
		{
			current_line = make_line(tail);
			tail = trim_tail(tail);
			free_tail(bytes_read, tail);
			break ;
		}
		if (!read_buffer(fd, buffer, &bytes_read) && !ft_strlen(tail))
			return (free(buffer), NULL);
	}
	return (free(buffer), current_line);
}
