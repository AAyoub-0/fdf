# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 20:15:38 by aayoub            #+#    #+#              #
#    Updated: 2025/02/25 14:37:40 by aboumall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= fdf

HEAD 	= includes/fdf.h includes/fdf_strings.h
LIBFT_A = libft.a

CC 		= cc

CFLAGS 	= -Werror -Wextra -Wall -Iincludes

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

CONTROL_DIR	=	$(SRC_DIR)/control
WINDOW_DIR	=	$(SRC_DIR)/window
DRAW_DIR	=	$(SRC_DIR)/draw
CLICK_DIR	=	$(CONTROL_DIR)/click
HOVER_DIR	=	$(CONTROL_DIR)/hover
INSTRU_DIR	=	$(WINDOW_DIR)/instruction
MAP_DIR		=	$(WINDOW_DIR)/map

CONTROL_SRC	=	controls.c hooks.c
CLICK_SRC	=	click.c click_utils.c
HOVER_SRC	=	close_ins_hv.c	colors_hv.c map_hv.c \
				map_hv_fr.c map_hv_sr.c map_hv_tr.c \
				project_hv.c rotation_hv.c view_hv.c
INSTRU_SRC	=	instruction.c instruction_utils.c
WINDOW_SRC	=	window.c
MAP_SRC		=	map.c map_utils.c
DRAW_SRC	=	point.c project.c \
				draw.c color.c \
				frame.c draw_utils.c
SRC_SRC 	= 	utils.c main.c

LIBFT 		= 	$(addprefix $(LIBFT_DIR)/, $(LIBFT_A))

SRC 		= 	$(addprefix $(SRC_DIR)/, $(SRC_SRC)) 			\
				$(addprefix $(CONTROL_DIR)/, $(CONTROL_SRC)) 	\
				$(addprefix $(HOVER_DIR)/, $(HOVER_SRC)) 		\
				$(addprefix $(CLICK_DIR)/, $(CLICK_SRC))		\
				$(addprefix $(WINDOW_DIR)/, $(WINDOW_SRC))		\
				$(addprefix $(INSTRU_DIR)/, $(INSTRU_SRC))		\
				$(addprefix $(MAP_DIR)/, $(MAP_SRC))			\
				$(addprefix $(DRAW_DIR)/, $(DRAW_SRC))
				
OBJ 		= 	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: mlx_lib lib $(NAME)

$(NAME): $(OBJ) $(HEAD) $(SRC)
	$(CC) $(OBJ) $(CFLAGS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEAD) Makefile | $(OBJ_DIR)
	@mkdir -p $(dir $@) > /dev/null
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

bonus: CFLAGS += -D FDF_BONUS=1
bonus: re

lib:
	@echo "Checking libft..."
	@if $(MAKE) -C $(LIBFT_DIR) -q; then \
		echo "Libft is already up to date!"; \
	else \
		echo "Making libft..."; \
		$(MAKE) -C $(LIBFT_DIR) > /dev/null; \
	fi

mlx_lib:
	@echo "Checking mlx lib..."
	@if $(MAKE) -C $(MLX_DIR) -q; then \
		echo "Mlx lib is already up to date!"; \
	else \
		echo "Making mlx lib..."; \
		$(MAKE) -C $(MLX_DIR) > /dev/null; \
	fi

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

.PHONY: all clean fclean re lib mlx_lib bonus