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
	static char	next_line[BUFFER_STATIC_SIZE];
	char	*current_line;
	char	*buffer;
	int	bytes_read;
	int	nbytes;
	int	i;
	int	j;
	int	index_nl;
	int	index_l;

	buffer = malloc(BUFFER_SIZE);
	current_line = malloc(BUFFER_STATIC_SIZE);
	nbytes = 0;
	index_l = 0;
	if (ft_strlen(next_line) == 0)
	{	
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		nbytes += bytes_read;
		while (bytes_read > 0)
		{
			//if (bytes_read < BUFFER_SIZE)
			//	truncate_buffer(buffer, bytes_read);
			index_nl = find_nl_index(buffer);
			if (index_nl > 0)
			{
				i = 0;
				while (buffer[i] != '\n')
				{
					current_line[index_l] = buffer[i];
					index_l++;
					i++;
				}
				current_line[index_l] = '\n';
				index_l++;
				j = 0;
				while (j < bytes_read - i)
				{
					next_line[j] = buffer[j + i]; 
					j++;
				}
				next_line[j] = '\0';
				break;
			}
			else
			{	
				j = 0;
				while (j < bytes_read)
				{
					current_line[j + index_l] = buffer[j];
					j++;
				}
				index_l += bytes_read;
				bytes_read = read(fd, buffer, BUFFER_SIZE);
			}
		}
	}
	else
	{
		while (next_line[index_l])
		{
			current_line[index_l] = next_line[index_l];
			index_l++;
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		while (bytes_read > 0)
		{
			index_nl = find_nl_index(buffer);
			if (index_nl > 0)
			{
				i = 0;
				while (buffer[i] != '\n')
				{
					current_line[index_l] = buffer[i];
					index_l++;
					i++;
				}
				current_line[index_l] = '\n';
				index_l++;
				j = 0;
				while (j < bytes_read - i)
				{
					next_line[j] = buffer[j + i]; 
					j++;
				}
				next_line[j] = '\0';
				break;
			}
			else
			{	
				j = 0;
				while (j < bytes_read)
				{
					current_line[j + index_l] = buffer[j];
					j++;
				}
				index_l += bytes_read;
				bytes_read = read(fd, buffer, BUFFER_SIZE);
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
