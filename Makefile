# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 20:15:38 by aayoub            #+#    #+#              #
#    Updated: 2025/02/14 18:53:16 by aboumall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= fdf

HEAD 	= fdf.h
LIBFT_A = libft.a

CC 		= cc

CFLAGS 	= -g

UNAME 	:= $(shell uname)

ifeq ($(UNAME), Darwin)
    MLX_DIR = ./minilibx
    MLX = $(MLX_DIR)/libmlx.a
    MLX_FLAGS = -framework OpenGL -framework AppKit -O3
else
    MLX_DIR = ./minilibx_linux
    MLX = $(MLX_DIR)/libmlx.a
    MLX_FLAGS = -lX11 -lXext -lm -lGL -lz -O3
endif

LIBFT_DIR 	= 	libft
SRC_DIR 	= 	src
OBJ_DIR 	= 	obj

SRC_SRC 	= 	test.c map.c point.c project.c				\
				window.c hooks.c draw.c color.c				\
				controls.c instruction.c frame.c			\
				view_ctl.c rotation_ctl.c project_ctl.c		\
				close_ins_ctl.c map_ctl.c map_utils.c		\
				utils.c main.c

LIBFT 		= 	$(addprefix $(LIBFT_DIR)/, $(LIBFT_A))
SRC 		= 	$(addprefix $(SRC_DIR)/, $(SRC_SRC))
OBJ 		= 	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEAD) $(LIBFT) $(MLX) $(SRC)
	$(CC) $(OBJ) $(CFLAGS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

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

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null
	@$(MAKE) clean -C $(MLX_DIR) > /dev/null

fclean: clean
	@echo "Removing executable and libraries..."
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null

re: fclean all

.PHONY: all clean fclean re libft mlx obj