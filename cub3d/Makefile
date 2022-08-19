# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 12:29:48 by mabdelou          #+#    #+#              #
#    Updated: 2022/08/04 12:29:53 by mabdelou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -g -fsanitize=address -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

RM = rm -f
NAME = cub3D
FILES = *.c \
		*/*.c

all:  $(NAME)

$(NAME): $(FILES)
	$(CC) $(FILES)  -o $(NAME)
	

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re bonus
