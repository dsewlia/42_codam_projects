CXX := c++
CXX_FLAGS := -Wall -Wextra -Werror -std=c++20
NAME := Span
SOURCE_CPP := main.cpp Span.cpp
SOURCE_HPP := Span.hpp
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