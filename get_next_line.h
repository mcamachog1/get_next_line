#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#ifndef BREAK_LINE
# define BREAK_LINE 10
#endif

#ifndef BUFFER_STATIC_SIZE
# define BUFFER_STATIC_SIZE 1024
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef	struct	s_line
{
	unsigned char	*line;
	struct s_line	*next;
} t_line;

char	*get_next_line(int fd);
char	*line_maker(const char *buffer, char *line, int size);
void	truncate_buffer(char *buffer, int size);
int	find_nl_index(char *buffer);
int	ft_strlen(const char *str);
int	utils_read(int fd, char *buffer, int *bytes_read);
char	*utils_make_line(char *buffer, char *current);
void	utils_make_tail(char *buffer, char *next, int bytes_read);
char	*utils_save_line(char *buffer, char *current, int bytes_read);
void	utils_get_tail(char *current, char *tail);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *s, int c);

#endif
