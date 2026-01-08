NAME        = pendu
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror


LIBFT_DIR   = libft/
LIBFT_A     = $(LIBFT_DIR)libft.a


SRCS        = main.c
OBJS        = $(SRCS:.c=.o)

all: $(NAME)


$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re