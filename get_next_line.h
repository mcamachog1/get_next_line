#ifndef BUFFER_SIZE
# define BUFFER_SIZE 80
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
int	find_nl_index(const char *buffer);

#endif
