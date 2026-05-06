CXX := c++
CXX_FLAGS := -Wall -Wextra -Werror -std=c++20
NAME := MutantStack
SOURCE_CPP := main.cpp
SOURCE_HPP := MutantStack.hpp
OBJFILES := $(SOURCE_CPP:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJFILES)
		$(CXX) -o $(NAME) $(OBJFILES)

%.o: %.cpp $(SOURCE_HPP)
	$(CXX) -c $(CXX_FLAGS) -o $@ $<

clean:
		rm -f $(OBJFILES)

fclean:
		rm -f $(NAME) $(OBJFILES)

re: fclean all

.PHONY: all clean fclean re