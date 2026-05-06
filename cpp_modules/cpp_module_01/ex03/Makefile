CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++17
NAME := weapon
SOURCE_CPP := HumanA.cpp HumanB.cpp Weapon.cpp main.cpp
SOURCE_HPP := HumanA.hpp HumanB.hpp Weapon.hpp
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