CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = get_next_line
SRC =	get_next_line.c \
		get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all





