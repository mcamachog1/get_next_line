/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:48:53 by macamach          #+#    #+#             */
/*   Updated: 2025/11/27 09:47:26 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

int	utils_read(int fd, char *buffer, int *bytes_read)
{

	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (*bytes_read == 0 || *bytes_read == -1)
		return (0);
	else
		return (1);
}

char *line_maker(const char *buffer, char *line, int size)
{
	static int	buffer_size;
	char	*new_line;
	int	i;
	int	j;

	buffer_size += size;
	i = 0;
	new_line = malloc(buffer_size);
	if (line != 0)
	{
		while (line[i])
		{
			new_line[i] = line[i];
			i++;
		}
		free(line);
	}
	j = 0;
	while (buffer[j] && j < BUFFER_SIZE && buffer[j] != '\n')
	{
		new_line[i + j] = buffer[j];
		j++;
	}
	j--;
	printf("\nUNA LINEA\n");
	printf("%s\n", new_line);
	if (buffer[j] == '\n')
		return new_line;
	else
		return(strdup("La linea continua"));
}

void truncate_buffer(char *buffer, int size)
{
	buffer[size - 1] = '\0';
}

int	find_nl_index(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (-1);
	return (i);
}
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
