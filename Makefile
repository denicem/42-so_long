# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 11:23:59 by dmontema          #+#    #+#              #
#    Updated: 2022/01/24 23:13:21 by dmontema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	so_long

SRC_DIR	:=	./src
SRCS	:=	$(SRC_DIR)/main.c \
			$(SRC_DIR)/parse_map.c \
			$(SRC_DIR)/draw_map.c \
			$(SRC_DIR)/check_map.c \
			$(SRC_DIR)/so_long_utils.c \
			$(SRC_DIR)/game.c \
			$(SRC_DIR)/game_info.c \
			$(SRC_DIR)/get_game_info.c \
			$(SRC_DIR)/game_exit.c

OBJS	:=	$(SRCS:.c=.o)

MLX_LIB	:=	mlx/libmlx.a
MLX_LIB_WIN	:=	mlx_linux/libmlx.a

CC	:=	gcc
CFLAGS :=	-Wall -Wextra -Werror -g
MLX_FLAGS	:=	-Imlx

LINK_MLX	:=	-Lmlx -lmlx -framework OpenGL -framework AppKit

LIBS := Libft/libft.a

all:	$(NAME) 

$(NAME):	$(MLX_LIB) $(LIBS) $(OBJS) 
	@$(CC) $(CFLAGS) $(LINK_MLX) $(LIBS) $(OBJS) -o $(NAME)
	

$(MLX_LIB):	
	@make -C mlx

MLX:
	@make -C mlx

.c.o:
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -c $< -o $(<:.c=.o)
	@echo "Compiling objects...\n"

$(LIBS):	
	@make -C Libft

clean:
	rm -f $(OBJS)
	make -C mlx clean
	make -C Libft clean

fclean:	clean
	rm -f $(NAME)

re:	fclean all