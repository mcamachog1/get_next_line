/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:48:53 by macamach          #+#    #+#             */
/*   Updated: 2025/11/24 15:49:02 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_next_line.h"

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

int	find_nl_index(const char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (-1);
	return (i);
}