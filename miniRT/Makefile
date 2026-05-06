CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := miniRT
INCLUDES = -I/usr/include -Imlx -I/libft/libft.a
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -L./libft -lft -lm
HEADERS := src/minirt.h
SRC_PATH := src/
SOURCE_FILES :=	main.c frame_ctl.c program_ctl.c \
			parcing/parce_rt_file.c parcing/parce_objects.c \
			parcing/parce_utils.c parcing/parce_utils_utils.c \
			parcing/parce_data_types.c parcing/rt_atof.c \
			mem_ctrl.c parcing/objects_linked_lists.c \
			error_printer.c \
			object_interaction/cylinder_interaction.c \
			object_interaction/plane_interaction.c \
			object_interaction/sphere_interaction.c \
			render/render.c \
			vec_maths/vec_maths_1.c \
			vec_maths/vec_maths_2.c \
			color_maths/color_maths_1.c \
			color_maths/color_maths_2.c \
			object_interaction/object_interaction.c \
			object_interaction/object_interaction_utils.c \
			color_maths/color_maths_3.c
SOURCES := $(addprefix $(SRC_PATH), $(SOURCE_FILES))
OBJFILES := $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJFILES)
	$(MAKE) all -C ./mlx
	$(MAKE) all -C ./libft
	$(CC) -o $(NAME) $(CFLAGS) $(OBJFILES) $(MLX_FLAGS) $(INCLUDES)

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	$(MAKE) clean -C ./mlx
	$(MAKE) clean -C ./libft
	rm -f $(OBJFILES)

fclean:
	$(MAKE) clean -C ./mlx
	$(MAKE) fclean -C ./libft
	rm -f $(NAME) $(OBJFILES)

re: fclean all

.PHONY: all clean fclean re
