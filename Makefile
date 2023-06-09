# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbricot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 17:08:54 by gbricot           #+#    #+#              #
#    Updated: 2023/04/18 19:10:38 by gbricot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =	sources/main.c \
	sources/ft_split.c \
	sources/ft_read_map.c \
	sources/ft_map_check.c \
	sources/ft_calloc.c \
	sources/ft_memcpy.c \
	sources/ft_itoa.c \
	sources/ft_render_map.c \
	sources/ft_actions.c \
	sources/ft_player_move.c \
	sources/ft_pathfinding.c \
	sources/ft_free_all.c \

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
