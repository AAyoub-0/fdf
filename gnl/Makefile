# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 17:59:46 by aayoub            #+#    #+#              #
#    Updated: 2025/01/02 22:23:42 by aayoub           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

HEAD = get_next_line.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c $(HEAD) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re