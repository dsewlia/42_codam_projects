# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 18:56:49 by dsewlia           #+#    #+#              #
#    Updated: 2025/03/27 13:41:28 by dsewlia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_REPO = https://github.com/codam-coding-college/MLX42.git

MLX_PATH = ./MLX42/

MLX_LIB = $(MLX_PATH)build/libmlx42.a

MLXFLAGS = -ldl -lglfw -pthread -lm

CFILES = \
			check_map.c \
			ft_printf_utils.c \
			ft_printf.c \
			ft_split.c \
			get_map.c \
			init_mlx.c \
			init_mlx_2.c \
			key_hook.c \
			main.c \

OBJS = $(CFILES:%.c=%.o)

all: libmlx $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX_PATH): 
	@git clone $(MLX_REPO) $(MLX_PATH)

libmlx: $(MLX_PATH)
	@cd $(MLX_PATH) && cmake -B build
	@cd $(MLX_PATH) && cmake --build build -j4

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(MLX_LIB) -o $(NAME)

clean: 
	@if [ -d "$(MLX_PATH)" ]; then cd $(MLX_PATH) && cmake --build build --target clean; fi
	@rm -rf $(MLX_PATH)
	@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx
