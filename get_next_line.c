#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"


static char *line_maker(const char *buffer, char *line, int size)
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
	while (buffer[j])
	{
		new_line[i + j] = buffer[j];
		j++;
	}
	return new_line;
}

int	main(void)
{
	int	fd;
	char	*buffer;
	char	*line;

	buffer = malloc(BUFFER_SIZE);
	fd = open("file.txt", O_RDONLY);
	read(fd, (void *)buffer, BUFFER_SIZE);
	line = line_maker(buffer, 0, BUFFER_SIZE);
	printf("buffer:%s\nline:%s\n", buffer, line);
	read(fd, (void *)buffer, BUFFER_SIZE);
	line = line_maker(buffer, line, BUFFER_SIZE);
	printf("buffer:%s\nline:%s\n", buffer, line);
	read(fd, (void *)buffer, BUFFER_SIZE);
	line = line_maker(buffer, line, BUFFER_SIZE);
	printf("buffer:%s\nline:%s\n", buffer, line);
	free(buffer);
	return (0);
}
