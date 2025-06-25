NAME = so_long
NAME_BONUS = so_long_bonus

SRC_DIR = src
VAL_DIR = $(SRC_DIR)/validation
PRINTF_DIR = ft_printf
LIBFT_DIR = $(PRINTF_DIR)/libft
MLX_DIR = minilibx-linux

MANDATORY_SRCS = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/gnl.c \
	$(SRC_DIR)/gnl_utils.c \
	$(VAL_DIR)/check_map.c \
	$(VAL_DIR)/check_map_utils.c \
	$(VAL_DIR)/helper_functions.c \
	$(SRC_DIR)/keep_map.c \
	$(SRC_DIR)/start_game.c \
	$(SRC_DIR)/key_handling.c \
	$(SRC_DIR)/free.c

BONUS_SRCS = \
	$(SRC_DIR)/main_bonus.c \
	$(SRC_DIR)/game_bonus.c \
	$(SRC_DIR)/game_utils_bonus.c \
	$(SRC_DIR)/gnl.c \
	$(SRC_DIR)/gnl_utils.c \
	$(VAL_DIR)/check_map.c \
	$(VAL_DIR)/check_map_utils.c \
	$(VAL_DIR)/helper_functions.c \
	$(SRC_DIR)/keep_map.c \
	$(SRC_DIR)/start_game.c \
	$(SRC_DIR)/key_handling.c \
	$(SRC_DIR)/free.c

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
MLX_LIB = $(MLX_DIR)/libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude -I$(PRINTF_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(MANDATORY_OBJS) $(PRINTF_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) $(PRINTF_LIB) $(MLX_LIB) $(MLX_FLAGS) -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS) $(PRINTF_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(PRINTF_LIB) $(MLX_LIB) $(MLX_FLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
