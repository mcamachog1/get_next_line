/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:48:23 by macamach          #+#    #+#             */
/*   Updated: 2025/11/27 17:33:34 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *tail;
	char *current_line;
	char *buffer;
	int bytes_read;

	bytes_read = 0;
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (ft_strlen(tail) != 0)
	{
		current_line = (char *)ft_calloc(ft_strlen(tail) + 1, sizeof(char));
		utils_get_tail(current_line, tail);
	}
	else
	{
		current_line = NULL;
		tail = NULL;	
	}
	if (!utils_read(fd, buffer, &bytes_read))
		return (free(buffer), NULL);
	while (bytes_read > 0)
	{
		if(ft_strchr(buffer, BREAK_LINE))
		{
			current_line = utils_make_line(buffer, current_line);
			tail = utils_make_tail(buffer, tail);
			break;
		}
		else
			current_line = utils_save_line(current_line, buffer, bytes_read);
		if (!utils_read(fd, buffer, &bytes_read) && !current_line)
			return (free(buffer), NULL);			
	}
	free(buffer);
	return (current_line);
}

int main(void)
{
	int fd;
	char *line;
	int count;

	count = 0;
	fd = open("file.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		count++;
		printf("[%d]:%s\n", count, line);
		free(line);
	}
	return (0);
}
