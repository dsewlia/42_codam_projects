CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Library $(NAME) created"
	
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "Obeject files removed"

fclean: clean
	rm -f $(NAME)
	@echo "Library $(NAME) removed"

re: fclean all

.PHONY: all clean fclean re
