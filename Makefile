SRCS = sources/main.c
OBJS = $(SRCS:.c=.o)
CC = clang
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = so_long

all: $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re