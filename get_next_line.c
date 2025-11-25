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

int	main(void)
{
	int	fd;
	char	*buffer;
	char	*line;
	int	bytes_read;


	buffer = malloc(BUFFER_SIZE);
	fd = open("file.txt", O_RDONLY);
	line = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (bytes_read < BUFFER_SIZE)
			truncate_buffer(buffer, bytes_read);
		line = line_maker(buffer, line, BUFFER_SIZE);
		printf("BUFFER_SIZE:%d\nBYTES_READ:%d\n", BUFFER_SIZE, bytes_read);
		printf("**** buffer *****\n");
		printf("%.*s\n", BUFFER_SIZE, buffer);
		printf("**** line   *****\n");
		printf("%.*s\n", (int)(strlen(line) - 1), line);
		bytes_read=read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
		printf("Error\n");
	free(buffer);
	return (0);
}
