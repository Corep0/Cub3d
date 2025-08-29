#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seruff <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 08:40:24 by seruff            #+#    #+#              #
#    Updated: 2025/08/29 15:47:26 by seruff           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
CC = cc
CF = -Wall -Werror -Wextra -g

# Include
HEAD_DIR = include
HEAD = $(HEAD_DIR)/cub3d.h
INC = 	-L$(LIBFT_DIR) -lft	\
 	-L$(MLX_DIR) -lmlx

# Source
SRC_DIR = src
UTIL_DIR = $(SRC_DIR)/utils
PARSE_DIR = $(SRC_DIR)/parsing
PLAYER_DIR = $(SRC_DIR)/player_check
TEXTURE_DIR = $(SRC_DIR)/init_texture
MOVEMENT_DIR = $(SRC_DIR)/movement
RAYCASTER_DIR = $(SRC_DIR)/raycaster
SRC =	$(SRC_DIR)/main.c			\
	$(PARSE_DIR)/initialization.c		\
	$(PARSE_DIR)/nature_of_file.c		\
	$(PARSE_DIR)/check_map.c		\
	$(PARSE_DIR)/utils_element_order.c	\
	$(PARSE_DIR)/utils_order.c		\
	$(PARSE_DIR)/split_element.c		\
	$(PARSE_DIR)/content.c			\
	$(PARSE_DIR)/content2.c			\
	$(PLAYER_DIR)/player.c			\
	$(TEXTURE_DIR)/init_dir.c		\
	$(TEXTURE_DIR)/size_map.c		\
	$(TEXTURE_DIR)/texture.c		\
	$(TEXTURE_DIR)/convert_rgb_image.c	\
	$(MOVEMENT_DIR)/key.c			\
	$(RAYCASTER_DIR)/raycaster.c		\
	$(UTIL_DIR)/utils.c			\
	$(UTIL_DIR)/exit.c			\
	$(UTIL_DIR)/free.c			\
	$(SRC_DIR)/init_window.c		\

# Minilibx
MLX_DIR = minilibx-linux/
MLX_NAME = libmlx.a
MLX = $(MLX_DIR)$(MLX_NAME)

# Program
PROG = cub3d

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

#Color
GC = \033[0;32m
RC = \033[0;31m
BC = \033[0;34m
ENDC = \033[0m

all:		$(LIBFT) $(MLX) $(PROG)

$(PROG):	$(SRC)
		@echo "$(GC)Compiling Cub3d program..$(ENDC)"
		$(CC) $(CF) -o $(PROG) $(SRC) $(MLX) $(LIBFT) $(INC) -I$(HEAD_DIR) -g -lXext -lX11 -lm
		@echo "$(RC)Program Cub3d is ready to be use$(ENDC)"

$(MLX):
		@echo "$(GC)Building MiniLibX$(ENDC)"
		@make all -C$(MLX_DIR)
		@echo "$(RC)MiniLibX is ready$(ENDC)"
$(LIBFT):
		@echo "$(GC)Building Libft$(ENDC)"
		@make all -C$(LIBFT_DIR)
		@echo "$(RC)Libft is ready$(ENDC)"

clean:
		@make fclean -C$(LIBFT_DIR)
		@make clean -C$(MLX_DIR)
		@echo "$(GC)Libft is clean$(ENDC)"
		@echo "$(GC)MinilibX is clean$(ENDC)"

fclean:		clean
		@rm -f $(PROG)

re:		fclean all

.PHONY:		re fclean clean all
