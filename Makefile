NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c $(HEADERS) Makefile
	$(CC) $(FLAGS) -c $< -o $@ -I .

clean:
	rm -rf $(OBJ) $(OBJ_B)

fclean: clean
	rm -rf $(NAME)

re: fclean 
	$(MAKE) $(NAME)

.PHONY : all bonus clean fclean re