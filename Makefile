# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/14 16:58:23 by rgwayne-          #+#    #+#              #
#    Updated: 2019/09/14 17:49:16 by rgwayne-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAG = -Wall -Wextra -Werror
SRC_FILES = main.c julia.c ship.c mandelbrot.c deal_keys.c deal_keys2.c errors.c pthread.c
SRC_DIR = src
OBJ_DIR = objects
SRC = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))
INC = -I /usr/local/include -I libft/
LIB = -lmlx -L libft/ -lft
LIBFT = libft/libft.a
FRWR = -framework OpenGL -framework OpenCL -framework AppKit
MAIN_INC = src/fractol.h

all: directory $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@gcc $(FLAG) $(OBJ) $(INC) $(LIB) $(FRWR) -o $@

$(LIBFT):
	@make -C libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(MAIN_INC)
	@gcc $(FLAGS) -c $< -o $@

directory: $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
    
clean:
	@make -C libft/ clean
	@rm -rf *.o
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)

re: fclean all