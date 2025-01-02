# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 20:15:38 by aayoub            #+#    #+#              #
#    Updated: 2025/01/02 18:24:49 by aayoub           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEAD = main.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
    MLX_DIR = ./minilibx
    MLX = $(MLX_DIR)/libmlx.a
    MLX_FLAGS = -framework OpenGL -framework AppKit
else
    MLX_DIR = ./minilibx-linux
    MLX = $(MLX_DIR)/libmlx.a
    MLX_FLAGS = -lX11 -lXext -lm -lGL
endif

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = ./gnl
GNL = $(GNL_DIR)/gnl.a

SRC_DIR = src
SRC = 	$(SRC_DIR)/parse_map.c

OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(HEAD) $(MLX) $(GNL)
	$(CC) main.c $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) $(GNL) $(MLX_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEAD) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	@echo "Making libft..."
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null

$(MLX):
	@echo "Making mlx lib..."
	@$(MAKE) -C $(MLX_DIR) > /dev/null

$(GNL):
	@echo "Making gnl lib..."
	@$(MAKE) -C $(GNL_DIR) > /dev/null

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null
	@$(MAKE) clean -C $(MLX_DIR) > /dev/null
	@$(MAKE) clean -C $(GNL_DIR) > /dev/null

fclean: clean
	@echo "Removing executable and libraries..."
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null
	@$(MAKE) clean -C $(MLX_DIR) > /dev/null
	@$(MAKE) fclean -C $(GNL_DIR) > /dev/null

re: fclean all

.PHONY: all clean fclean re