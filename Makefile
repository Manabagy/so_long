MLX = -lmlx -lXext -lX11 -lm
NAME = so_long

all:
	gcc -Wall -Wextra -Werror main.c -o $(NAME) $(MLX)
