#ifndef BUFFER_SIZE
# define BUFFER_SIZE 80
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
void	utils_make_line(char *buffer, char *current, int *index);
void	utils_next_line(char *buffer, char *next, int bytes_read);
void	utils_save_line(char *buffer, char *current, int bytes_read, int *index);
void	utils_next_to_current(char *current, char *next, int *index);
void	*ft_memset(void *s, int c, size_t n);

#endif
