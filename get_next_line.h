#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


typedef	struct	s_line
{
	unsigned char	*line;
	struct s_line	*next;
} t_line;

#endif
