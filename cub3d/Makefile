# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 15:53:14 by ahmez-za          #+#    #+#              #
#    Updated: 2022/09/04 15:55:11 by ahmez-za         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc -g -fsanitize=address -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

RM = rm -f
NAME = cub3D
LIBFT = libft/libft.a
FILES = *.c \
		*/*.c

all:  $(NAME)

$(NAME): $(FILES)
	cd libft && make && cd ..
	$(CC) $(FILES)  -o $(NAME) $(LIBFT)
	

clean:
	cd libft && rm -rf libft.a && cd ..
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re bonus
