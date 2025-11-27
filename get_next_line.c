/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:48:23 by macamach          #+#    #+#             */
/*   Updated: 2025/11/27 13:34:48 by macamach         ###   ########.fr       */
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
	static char	next_line[BUFFER_STATIC_SIZE];
	char		*current_line;
	char		*buffer;
	int			bytes_read;
	int			index_l;

	buffer = malloc(BUFFER_SIZE);
	current_line = malloc(BUFFER_STATIC_SIZE);
	index_l = 0;
	if (ft_strlen(next_line) == 0)
	{
		if (!utils_read(fd, buffer, &bytes_read))
			return (NULL);
		while (bytes_read > 0)
		{
			if (find_nl_index(buffer) > 0)
			{
				utils_make_line(buffer, current_line, &index_l);
				utils_next_line(buffer, next_line, bytes_read);
				break ;
			}
			else
			{
				utils_save_line(buffer, current_line, bytes_read, &index_l);
				if (!utils_read(fd, buffer, &bytes_read))
					return (NULL);
			}
		}
	}
	else
	{
		utils_next_to_current(current_line, next_line, &index_l);
		if (!utils_read(fd, buffer, &bytes_read))
			return (NULL);
		while (bytes_read > 0)
			{
			if (find_nl_index(buffer) > 0)
			{
				utils_make_line(buffer, current_line, &index_l);
				utils_next_line(buffer, next_line, bytes_read);
				break ;
			}
			else
			{
				utils_save_line(buffer, current_line, bytes_read, &index_l);
				if (!utils_read(fd, buffer, &bytes_read))
					return (NULL);
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
	printf("XX1\n");
	next_line = get_next_line(fd);
	printf("\n%s\n", next_line);
	free(next_line);
	printf("XX2\n");
	next_line = get_next_line(fd);
	printf("\n%s\n", next_line);
	free(next_line);
	printf("XX3\n");
	next_line = get_next_line(fd);
	printf("\n%s\n", next_line);
	free(next_line);
	return (0);
}
