NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MY_SOURCES = ft_printf.c ft_printf_h1.c ft_printf_h2.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS)
clean:
	rm -f $(MY_OBJECTS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

