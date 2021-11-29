SRCS = sources/main.c sources/ft_strlen.c sources/lst.c
OBJS = $(SRCS:.c=.o)
CC = clang
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = so_long
MINILIBX_DIR = minilibx-linux/libmlx.a -lX11 -lXext #-I /usr/X11/include -g -L /usr/X11/lib -lX11 -L./minilibx-linux -lmlx -lXext
MLX = minilibx-linux/

all: $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	make -C $(MLX)
	$(CC) $(FLAGS) $(SRCS) $(MINILIBX_DIR) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
