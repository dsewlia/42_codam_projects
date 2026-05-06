CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++17
NAME := generate
SOURCE_CPP := main.cpp Base.cpp
SOURCE_HPP := Base.hpp A.hpp B.hpp C.hpp
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