NAME = libftprintf.a
CC = gcc
CFLAG = -Wall -Werror -Wextra
SRC_FILES = ft_printf.c \
			ft_printf_utils.c \
			ft_bonus.c \
			ft_bonus_b.c \
			ft_bonus_c.c

HEADER = ft_printf.h
LIBC = ar rcs

OBJS = $(SRC_FILES:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAG) $^

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

bonus: $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re