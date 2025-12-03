SOURCES = get_next_line.c get_next_line_utils.c main.c

OBJS = $(SOURCES:.c=.o)

FLAGS = -Wall -Werror -Wextra

compile: $(OBJS)
		cc $(FLAGS) $(SOURCES) -o test

buffer: $(OBJS)
		cc $(FLAGS)  $(SOURCES) -o test

debug: $(OBJS)
		cc -g $(FLAGS) $(SOURCES) -o test
clean:
		rm $(OBJS)

fclean: clean
		rm test
