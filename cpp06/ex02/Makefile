NAME=real_type

CC=clang++
CFLAGS=-Wall -Werror -Wextra #-g3 -fsanitize=address

INC=$(wildcard *.hpp)
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
