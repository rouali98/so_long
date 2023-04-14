# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 12:15:38 by rouali            #+#    #+#              #
#    Updated: 2023/03/10 12:15:39 by rouali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC =	so_long.c \
		check_cpe.c \
		check_img.c \
		check_lines.c \
		count.c \
		exit.c \
		move.c \
		put_img.c \
		so_long_utils.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all