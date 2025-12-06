/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:47:01 by macamach          #+#    #+#             */
/*   Updated: 2025/12/03 16:07:10 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef BREAK_LINE
#  define BREAK_LINE 10
# endif

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
int		read_buffer(int fd, char *buffer, int *bytes_read);
char	*utils_make_line(char *buffer, char *current);
char	*utils_make_tail(char *buffer, int bytes_read);
char	*utils_save_line(char *buffer, char *current, int bytes_read);
char	*utils_get_tail(char *current, char *tail);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*make_line(char *tail);
char	*append_tail(char *tail, const char *buffer);
char	*trim_tail(char *tail);
void	free_tail(int bytes_read, char *tail);

#endif
