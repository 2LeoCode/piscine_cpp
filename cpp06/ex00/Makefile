NAME=litteral

CC=clang++
CFLAGS=-Wall -Werror -Wextra #-g3 -fsanitize=address
LFLAGS=-lm

INC=$(wildcard *.hpp)
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
