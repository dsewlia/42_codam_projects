CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME:= philo
HEADERS := philo.h
SRCS:= main.c init.c sim.c
OBJS:= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

%.o: %.c $(HEADERS)

clean:
		rm -f $(OBJS)

fclean:
		rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re