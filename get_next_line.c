#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char *line_maker(const char *buffer, char *line, int size)
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
	while (buffer[j] && j < BUFFER_SIZE)
	{
		new_line[i + j] = buffer[j];
		j++;
	}
	return new_line;
}

static void truncate_buffer(char *buffer, int size)
{
	buffer[size - 1] = '\0';
}

int	main(void)
{
	int	fd;
	char	*buffer;
	char	*line;
	int	bytes_read;

	buffer = malloc(BUFFER_SIZE);
	fd = open("file.txt", O_RDONLY);
	line = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (bytes_read < BUFFER_SIZE)
			truncate_buffer(buffer, bytes_read);
		line = line_maker(buffer, line, BUFFER_SIZE);
		printf("BUFFER_SIZE:%d\nBYTES_READ:%d\n", BUFFER_SIZE, bytes_read);
		printf("**** buffer *****\n");
		printf("%.*s\n", BUFFER_SIZE, buffer);
		printf("**** line   *****\n");
		printf("%.*s\n", (int)(strlen(line) - 1), line);
		bytes_read=read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
		printf("Error\n");
	free(buffer);
	return (0);
}
