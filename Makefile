NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

GNL_SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

MY_SOURCES =	main.c \
				map_array.c \
				map_check.c \
				map_helper.c \
				map_screen.c \
				map_valid.c \
				error_handle.c \
				game_logic.c \
				game_move.c \
				$(GNL_SRCS)

MY_OBJECTS = $(MY_SOURCES:.c=.o)

PRINTF_DIR = printf
LIBFT_DIR = libft

PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBS = $(PRINTF_LIB) $(LIBFT_LIB)

MLX_FLAGS = -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(MY_OBJECTS) $(LIBS)
	$(CC) $(CFLAGS) -o $@ $(MY_OBJECTS) $(LIBS) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(MY_OBJECTS)
	-$(MAKE) -C $(PRINTF_DIR) clean
	-$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	-$(MAKE) -C $(PRINTF_DIR) fclean
	-$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
