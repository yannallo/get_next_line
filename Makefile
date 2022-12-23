FLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c

all:
	gcc $(FLAGS) $(SRC)

clean:
	rm -rf $(NAME)

.PHONY : all clean