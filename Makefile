NAME = so_long
PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
# MLX = -lmlx -lXext -lX11 -lm

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c src/gnl.c src/gnl_utils.c src/validation/check_map.c src/validation/check_map_utils.c src/validation/helper_functions.c src/keep_map.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(PRINTF)

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	make -C $(PRINTF_DIR) clean
	rm -f $(OBJ)


fclean: clean
	make -sC $(PRINTF_DIR) fclean
	rm -f $(NAME) $(BONUS)


re: fclean all bonus

.PHONY: clean fclean re all bonus