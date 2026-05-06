CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++17
NAME := Braiiiiinnnnz
SOURCE_CPP := newZombie.cpp randomChump.cpp Zombie.cpp main.cpp
SOURCE_HPP := Zombie.hpp
OBJFILES := $(SOURCE_CPP:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJFILES)
		$(CC) -o $(NAME) $(OBJFILES)

%.o: %.cpp $(SOURCE_HPP)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
		rm -f $(OBJFILES)

fclean:
		rm -f $(NAME) $(OBJFILES)

re: fclean all

.PHONY: all clean fclean re