/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:48:53 by macamach          #+#    #+#             */
/*   Updated: 2025/12/03 14:46:30 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <unistd.h>
#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
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

void	free_tail(int bytes_read, char *tail)
{
	if (bytes_read == 0 && ft_strlen(tail) == 0)
		free(tail);
}
