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

CC	:=	gcc
CFLAGS :=	-Wall -Wextra -Werror
MLX_FLAGS	:=	-Imlx

LINK_MLX	:=	-Lmlx -lmlx -framework OpenGL -framework AppKit

all:	$(NAME) 

$(NAME):	$(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(LINK_MLX) $(OBJS) -o $(NAME)

$(MLX_LIB):	
	make -C mlx

MLX:
	make -C mlx

.c.o:
	$(CC) $(CFLAGS) $(MLX_FLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJS)
	make -C mlx clean

fclean:	clean
	rm -f $(NAME)

re:	fclean all