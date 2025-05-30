NAME = so_long
PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX = -Lmlx_Linux -lmlx_Linux -L ./minilibx-linux -Imlx_Linux -lXext -lX11 -lm -lz

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c src/gnl.c src/gnl_utils.c src/validation/check_map.c src/validation/check_map_utils.c src/validation/helper_functions.c src/keep_map.c src/init_game.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(PRINTF) $(MLX)

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	make -C $(PRINTF_DIR) clean
	rm -f $(OBJ)


fclean: clean
	make -C $(PRINTF_DIR) fclean
	rm -f $(NAME) $(BONUS)


re: fclean all

.PHONY: clean fclean re all bonus