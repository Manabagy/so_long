NAME = libftprintf.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c functions.c puthex.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(LIBFT) ft_printf.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ)


fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)


re: fclean all

.PHONY: clean fclean re all
