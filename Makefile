NAME = so_long
NAME_BONUS = so_long_bonus
CC = gcc
CFLAGS = -Wall -Werror -Wextra
PRINTF = libftprintf.a
SRC_FILES = main.c \
			ft_split.c \
			ft_error.c \
			ft_playability.c \
			ft_play_utils.c \
			ft_play_utils_b.c\
			ft_play.c \

SRC_FILES_BONUS = main_bonus.c \
				ft_split_bonus.c \
				ft_playability_bonus.c \
				ft_play_utils_bonus.c \
				ft_play_utils_b_bonus.c \
				ft_play_bonus.c \
				ft_error_bonus.c \
				ft_enemy_set_bonus.c \
				ft_enemy_ia_bonus.c \
				ft_enemy_crazy_ia_bonus.c \

INCLUDE = so_long.h

INCLUDE_BONUS = so_long_bonus.h

OBJS = $(SRC_FILES:.c=.o)

OBJS_BONUS = $(SRC_FILES_BONUS:.c=.o)

all: lib $(NAME)

bonus: lib $(NAME_BONUS)

%.o: %.c
	$(CC) -c $(CFLAG) -Ilibmlx $^ 

%.o: %.c
	$(CC) -c $(CFLAG) -Ilibmlx $^ 

lib:
	make -C ft_printf
	make -C libmlx
	cp ft_printf/$(PRINTF) $(PRINTF)

$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) libmlx/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)


$(NAME_BONUS): $(OBJS_BONUS) $(INCLUDE_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(PRINTF) libmlx/libmlx.a -framework OpenGL -framework AppKit -o $(NAME_BONUS)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	rm -f $(PRINTF)
	make -C ft_printf clean
	make -C libmlx clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re lib