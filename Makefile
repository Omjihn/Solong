# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbricot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 17:08:54 by gbricot           #+#    #+#              #
#    Updated: 2023/03/28 18:21:28 by gbricot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

#CFLAGS = -Wall -Wextra -Werror

SRC =	sources/main.c \
	sources/ft_read_map.c \
	sources/ft_res.c \
	sources/ft_get_images.c \
	sources/get_next_line.c \
	sources/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

LIB = Printf/libftprintf.a minilibx-linux/libmlx_Linux.a 

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all: mlx printf $(NAME)

mlx: 
	cd minilibx-linux && make

printf:
	cd Printf && make

clean: 
	rm -f $(OBJ)

fclean: clean 
	rm -f so_long

re: fclean all
