/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:48:53 by macamach          #+#    #+#             */
/*   Updated: 2025/12/02 16:29:33 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while(str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	if ((unsigned char)c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	max;
	size_t	init_len_dst;

	if (!dst && !src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	init_len_dst = ft_strlen(dst);
	if (size < init_len_dst + 1)
		return (size + ft_strlen(src));
	i = 0;
	max = size - (init_len_dst + 1);
	while (i < max && src[i])
	{
		dst[init_len_dst + i] = src[i];
		i++;
	}
	dst[init_len_dst + i] = '\0';
	return (init_len_dst + ft_strlen(src));
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*pointer;
	unsigned long	i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > INT_MAX / size)
		return (NULL);
	pointer = malloc(nmemb * size);
	if (pointer == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		pointer[i] = 0;
		i++;
	}
	return (pointer);
}

int	utils_read(int fd, char *buffer, int *bytes_read)
{
	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (*bytes_read <= 0)
		return (0);
	else
	{
		buffer[BUFFER_SIZE] = '\0';
		return (1);
	}
}

char	*utils_make_line(char *buffer, char *current)
{
	size_t	sb;
	size_t	sc;
	size_t	size;
	char	*line;

	sb = 0;
	sc = ft_strlen(current);
	while (buffer[sb] != '\n')
		sb++;
	size = sb + sc + 1;
	line = (char *)ft_calloc(size + 1, sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcat(line, current, sc + 1);
	ft_strlcat(line, buffer, size + 1); 
	free(current);
	return (line);
}

char	*utils_save_line(char *buffer, char *current, int bytes_read)
{
	size_t	sc;
	size_t	size;
	char	*line;

	sc = ft_strlen(current);
	size = bytes_read + sc + 1;
	line = (char *)ft_calloc(size + 1, sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcat(line, current, sc + 1);
	ft_strlcat(line, buffer, size);
	free(current);
	return (line);
}

char	*utils_make_tail(char *buffer, int bytes_read)
{
	int	i;
	int	j;
	char	*tail;

	i = 0;
	while(buffer[i] != '\n' && i < bytes_read)
		i++;
	tail = (char *)ft_calloc(bytes_read - (i + 1) + 1, sizeof(char));
	if(!tail)
		return(NULL);
	j = 0;
	i++;
	while(j < bytes_read - i )
	{
		tail[j] = buffer[j + i];
		j++;
	}
	tail[j] = '\0';
	return (tail);
}

char	*utils_get_tail(char *current, char *tail)
{
	int	i;
	int	j;
	int	last;
	char	*new_tail;

	new_tail = (char *)ft_calloc(ft_strlen(tail) + 1, sizeof(char));
	last = 0;
	if (ft_strlen(current) > 0)
		last = ft_strlen(current) - 1;
	i = 0;
	while(tail[i] && tail[i] != BREAK_LINE)
	{
		current[i + last] = tail[i];
		i++;
	}
	current[i + last] = tail[i];
	current[i + last + 1] = '\0';
	j = 0;
	i++;
	while(tail[i + j])
	{
		new_tail[j] = tail[j + i];
		j++; 
	}
	new_tail[j] = '\0';
	free(tail);
	return (new_tail);
}

