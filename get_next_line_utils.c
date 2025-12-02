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

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

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
	if (ft_strlcat(line, current, sc + 1) >= sizeof(line))
		return (free(line), NULL);
	if (ft_strlcat(line, buffer, size + 1) >= sizeof(line))
		return (free(line), NULL);
	free(current);
	return (line);
}

char	*utils_save_line(char *current, char *buffer, int bytes_read)
{
	size_t	sc;
	size_t	size;
	char	*line;

	sc = ft_strlen(current);
	size = bytes_read + sc;
	line = (char *)ft_calloc(size + 1, sizeof(char));
	if (!line)
		return (NULL);
	if (ft_strlcat(line, current, sc + 1) >= sizeof(line))
		return (free(line), NULL);
	if (ft_strlcat(line, buffer, bytes_read + 1) >= sizeof(line))
		return (free(line), NULL);
	line[size] = '\0';
	free(current);
	return (line);
}

char	*utils_make_tail(char *buffer, char *tail)
{
	size_t	sb;
	size_t	st;
	size_t	size;
	char	*line;
	char	*temp;

	temp = ft_strchr(buffer, BREAK_LINE);
	temp++;
	sb = ft_strlen(temp);
	st = ft_strlen(tail);
	size = sb + st;
	line = (char *)ft_calloc(size + 1, sizeof(char));
	if (!line)
		return (NULL);
	if (ft_strlcat(line, tail, st + 1) >= sizeof(line))
		return (free(line), NULL);
	if (ft_strlcat(line, temp, size + 1) >= sizeof(line))
		return (free(line), NULL);
	free(tail);
	return (line);
}

void	utils_get_tail(char *current, char *tail)
{
	int	i;
	int	last;

	last = 0;
	if(ft_strlen(current)>0)
		last = ft_strlen(current) - 1;
	i = 0;
	while(tail[i])
	{
		current[i + last] = tail[i];
		i++;
	}
	current[i + last] = '\0';
	free(tail);
	tail = NULL;
}

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
