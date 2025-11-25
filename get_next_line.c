/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:48:23 by macamach          #+#    #+#             */
/*   Updated: 2025/11/24 15:48:43 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*next_line;
	char	*current_line;
	char	*buffer;
	int	bytes_read;
	int	i;
	int	j;
	int	index;

	if (next_line == NULL)
	{	
		next_line = malloc(10000);
		current_line = 0;
		buffer = malloc(BUFFER_SIZE);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < BUFFER_SIZE)
			truncate_buffer(buffer, bytes_read);
		i = 0;
		while (bytes_read > 0)
		{
			index = find_nl_index(buffer);
			if (index > 0)
			{
				current_line = malloc(index + 1);
				while (buffer[i] != '\n')
				{
					current_line[i] = buffer[i];
					i++;
				}
				current_line[i] = '\n';
				i++;
				j = 0;
				while (j < bytes_read - i)
				{
					next_line[j] = buffer[j+ i]; 
					j++;
				}
				break;
			}
		}
	}
	free(buffer);
	return (current_line);
}

int	main(void)
{
	int	fd;
	char	*next_line;

	fd = open("file.txt", O_RDONLY);
	next_line = get_next_line(fd);
	printf("\n%s\n", next_line);
	free(next_line);
	return (0);
}
