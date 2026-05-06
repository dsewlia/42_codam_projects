CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRCS = push_swap.c push_swap_utils.c split_atoi.c last_handles.c step_cal.c instructions_1.c instructions_2.c input_parse.c
OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	@echo "Obeject files removed"

fclean: clean
	rm -f $(NAME)
	@echo "Library $(NAME) removed"

re: fclean all

.PHONY: all clean fclean re
