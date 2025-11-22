#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static	int	count_bytes(unsigned char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
		i++;
	return (i);
}

static int	line_maker(const char *buffer, int size)
{
	static int buffer_size;

	buffer_size += buffer_size;
	unsigned char	*read;
	int	bytes;

	bytes = count_bytes(*line)

}

int	main(void)
{
	int	fd;
	unsigned char	*buffer;

	buffer = malloc(BUFFER_SIZE);
	fd = open("file.txt", O_RDONLY);
	read(fd, (void *)buffer, BUFFER_SIZE);
	printf("%s\n", buffer);
	free(buffer);
	return (0);
}
