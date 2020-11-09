# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 14:08:59 by cvoltorb          #+#    #+#              #
#    Updated: 2020/11/09 22:13:21 by cvoltorb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
FLAGS = -Wall -Wextra -Werror -I ./includes

SRC = cub3d.c parser/parser.c parser/parse_map.c parser/parse_params.c parser/parse_tex_res.c \
		parser/parse_utils.c engine/angles.c engine/angles_utils.c engine/ft_draw.c \
		engine/ft_draw_utils.c engine/get_player_coord.c engine/handle_keys.c \
		engine/init.c engine/raycast.c engine/screen.c engine/utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(MAKE) -C mlx
		@$(MAKE) -C libft
		@cp mlx/libmlx.dylib .
		@cp libft/libft.a .
		@$(CC) -o $(NAME) $(FLAGS) $(OBJ) libft.a libmlx.dylib

clean:
		@rm -rf $(OBJ)
		@rm -rf *.bmp
		@$(MAKE) clean -C libft

fclean: clean
		@rm -rf libmlx.dylib
		@rm -rf libft.a
		@rm -rf $(NAME)
		@$(MAKE) fclean -C libft
		@$(MAKE) clean -C mlx

re: fclean all

.PHONY: all clean fclean re
