#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
//#include "get_next_line.h"
#define BUFFER_SIZE 10

int f1(void)
{
	static	int	counter;

	counter++;
	return counter;
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
	printf("counter:%d\n",f1());
	printf("counter:%d\n",f1());
	printf("counter:%d\n",f1());
}
