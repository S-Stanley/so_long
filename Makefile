SRCS = \
	sources/main.c sources/string_utils.c sources/lst.c sources/matrice.c \
	sources/draw.c sources/color.c sources/parsing.c sources/check_map.c \
	sources/pixel.c sources/win.c sources/ft_itoa.c sources/hook.c \
	sources/movement.c sources/player.c sources/exit.c sources/move.c 
OBJS = $(SRCS:.c=.o)
CC = clang
FLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
NAME = so_long
MINILIBX_DIR = minilibx-linux/libmlx.a -lX11 -lXext
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
