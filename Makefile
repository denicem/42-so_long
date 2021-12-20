# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 11:23:59 by dmontema          #+#    #+#              #
#    Updated: 2021/12/17 02:56:04 by dmontema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	so_long

SRC_DIR	:=	./src
SRCS	:=	$(SRC_DIR)/main.c
OBJS	:=	$(SRCS:.c=.o)

MLX_LIB	:=	mlx/libmlx.a
MLX_LIB_WIN	:=	mlx_linux/libmlx.a

CC	:=	gcc
CFLAGS :=	-Wall -Wextra -Werror
MLX_FLAGS	:=	-Imlx
MLX_FLAGS_WIN	:=	-I/usr/include -Imlx_linux -03

LINK_MLX	:=	-Lmlx -lmlx -framework OpenGL -framework AppKit
LINK_MLX_WIN	:=	-Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all:	$(NAME) 

$(NAME):	$(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(LINK_MLX) $(OBJS) -o $(NAME)

win:	$(win-obj) $(MLX_LIB_WIN)
	$(CC) $(CFLAGS) $(LINK_MLX_WIN) $(OBJS) -o $(NAME)

$(MLX_LIB):	
	make -C mlx

$(MLX_LIB_WIN):	
	make -C mlx_linux

MLX:
	make -C mlx

.c.o:
	$(CC) $(CFLAGS) $(MLX_FLAGS) -c $< -o $(<:.c=.o)

win-obj:
	$(CC) $(CFLAGS) $(MLX_FLAGS_WIN) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJS)
	make -C mlx clean

fclean:	clean
	rm -f $(NAME)

re:	fclean all