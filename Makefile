NAME = so_long
PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX = -lmlx -lXext -lX11 -lm

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c validation/check_map.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(PRINTF) $(MLX)

$(PRINTF): $(PRINTF_DIR)
	make -C $(PRINTF_DIR)

clean:
	make -C $(PRINTF_DIR) clean
	rm -f $(OBJ)


fclean: clean
	make -C $(PRINTF_DIR) fclean
	rm -f $(NAME) $(BONUS)


re: fclean all bonus

.PHONY: clean fclean re all bonus