CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++17 -g
# CFLAGS += -fsanitize=address -g -O0
NAME := ircserv
SOURCE_HPP := Socket.hpp Channel.hpp Server.hpp User.hpp Message.hpp Logger.hpp
SOURCE_CPP := main.cpp Server.cpp Channel.cpp Socket.cpp User.cpp Message.cpp commands.cpp Logger.cpp
SRC_PATH := src/
SOURCES := $(addprefix $(SRC_PATH), $(SOURCE_CPP))
HEADERS := $(addprefix $(SRC_PATH), $(SOURCE_HPP))
OBJFILES := $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJFILES)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJFILES)

%.o: %.cpp $(HEADERS)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJFILES)

fclean:
	rm -f $(NAME) $(OBJFILES)

re: fclean all

.PHONY: all clean fclean re
