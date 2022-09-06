# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 19:08:22 by ahmez-za          #+#    #+#              #
#    Updated: 2022/09/06 17:34:30 by ahmez-za         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

RM = rm -f
NAME = cub3D
LIBFT = ./libft/libft.a
FILES = *.c \
		*/*.c

all:  $(NAME)

$(NAME): $(FILES)
	cd libft && make && cd ..
	$(CC) $(FILES)  -o $(NAME) $(LIBFT)
	

clean:
	cd libft && make clean && cd ..
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re bonus
