# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 11:23:59 by dmontema          #+#    #+#              #
#    Updated: 2022/02/02 11:56:33 by dmontema         ###   ########.fr        #
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

OBJS_DIR	:=	./obj
OBJS	:=	$(SRCS:.c=.o)

MLX_LIB	:=	mlx/libmlx.a
MLX_LIB_WIN	:=	mlx_linux/libmlx.a

CC	:=	gcc
CFLAGS :=	-Wall -Wextra -Werror -g
MLX_FLAGS	:=	-Imlx

LINK_MLX	:=	-Lmlx -lmlx -framework OpenGL -framework AppKit

LIBS := Libft/libft.a

GREEN	:=	\033[0;32m
CYAN	:=	\033[0;36m
RESET	:=	\033[0m

all:	$(NAME) 

$(NAME):	$(MLX_LIB) $(LIBS) $(OBJS) 
	@echo "$(CYAN)Compiling so_long...$(RESET)"
	@$(CC) $(CFLAGS) $(LINK_MLX) $(LIBS) $(OBJS) -o $(NAME)
	@mkdir -p $(OBJS_DIR)
	@mv $(OBJS) $(OBJS_DIR)
	@echo " $(GREEN)\tCOMPLETE!$(RESET)"

$(MLX_LIB):	
	@echo "$(CYAN)Compiling MLX...$(RESET)"
	@make -C mlx

.c.o:
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -c $< -o $(<:.c=.o)

$(LIBS):	
	@echo "$(CYAN)Compiling Libft... $(RESET)"
	@make -C Libft

clean:
	@rm -f $(OBJS_DIR)/*
	@rmdir $(OBJS_DIR)
	@make -C mlx clean
	@make -C Libft clean
	@echo "$(GREEN)Cleaning done.$(RESET)"

fclean:	clean
	@rm -f $(NAME)
	@make -C Libft fclean

re:	fclean all

norm:
	norminette -R CheckForbiddenSourceHeader inc
	norminette -R CheckForbiddenSourceHeader ./src
	norminette -R CheckForbiddenSourceHeader ./Libft
