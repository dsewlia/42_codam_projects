CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++17
NAME := ex01
SOURCE_CPP := main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
SOURCE_HPP := Animal.hpp Dog.hpp Cat.hpp Brain.hpp
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