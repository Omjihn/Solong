# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbricot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 17:08:54 by gbricot           #+#    #+#              #
#    Updated: 2023/03/30 21:45:48 by gbricot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

#CFLAGS = -Wall -Wextra -Werror

SRC =	sources/main.c \
	sources/ft_split.c \
	sources/ft_gnl_map.c \
	sources/ft_calloc.c \
	sources/ft_memcpy.c \

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
