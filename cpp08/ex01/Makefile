NAME=span

CC=c++
CFLAGS=-Wall -Werror -Wextra #-g3 -fsanitize=address

INC=span.hpp
SRC=$(addsuffix .cpp, span main)
OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp $(INC) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
