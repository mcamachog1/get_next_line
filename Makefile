SOURCES = get_next_line.c get_next_line_utils.c

OBJS = $(SOURCES:.c=.o)

FLAGS = -Wall -Werror -Wextra

compile: $(OBJS)
		cc $(FLAGS) -D BUFFER_SIZE=150 $(SOURCES) -o test

clean:
		rm $(OBJS)

fclean: clean
		rm test
