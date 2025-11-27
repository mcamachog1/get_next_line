/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:48:53 by macamach          #+#    #+#             */
/*   Updated: 2025/11/27 17:35:59 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > INT_MAX / size)
		return (NULL);
	pointer = malloc(nmemb * size);
	if (pointer == NULL)
		return (NULL);
	ft_memset(pointer, 0, nmemb * size);
	return (pointer);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*new_pointer;

	new_pointer = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		new_pointer[i] = c;
		i++;
	}
	return (s);
}

int	utils_read(int fd, char *buffer, int *bytes_read)
{

	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (*bytes_read == 0 || *bytes_read == -1)
		return (0);
	else
		return (1);
}

void	utils_make_line(char *buffer, char *current, int *index)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n')
	{
		current[*index] = buffer[i];
		(*index)++;
		i++;
	}
	current[*index] = '\n';
	(*index)++;
}

void	utils_save_line(char *buffer, char *current, int bytes_read, int *index)
{
	int	j;

	j = 0;
	while (j < bytes_read)
	{
		current[j + *index] = buffer[j];
		j++;
	}
	*index += bytes_read;
}

void	utils_next_line(char *buffer, char *next, int bytes_read)
{
	int	i;
	int	j;

	i = 0;
	while(buffer[i] != '\n' && i < bytes_read)
		i++;
	j = 0;
	while(j < bytes_read - (i + 1))
	{
		next[j] = buffer[j + i];
		j++;
	}
	next[j] = '\0';
}

void	utils_next_to_current(char *current, char *next, int *index)
{
	while(next[*index])
	{
		current[*index] = next[*index];
		(*index)++;
	}
	ft_memset(next, 0, BUFFER_STATIC_SIZE);
}
/*
void	utils_split_buffer(int *bytes_read, char *current, char *next, int *index)
{
	while (*bytes_read > 0)
	{
		if (find_nl_index(buffer) > 0)
		{
			utils_make_line(buffer, current, index);
			utils_next_line(buffer, next, *bytes_read);
			break ;
		}
		else
		{
			utils_save_line(buffer, current, *bytes_read, index);
			if (!utils_read(fd, buffer, bytes_read))
				return (NULL);
		}
	}
}*/		

char *line_maker(const char *buffer, char *line, int size)
{
	static int	buffer_size;
	char	*new_line;
	int	i;
	int	j;

	buffer_size += size;
	i = 0;
	new_line = malloc(buffer_size);
	if (!new_line)
		return (free(new_line), NULL);	
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
