NAME=push_swap
CC=cc
CFLAGS=-g3
LIBFT=libft/libft.a
INCLUDES=-Ilibft -I.
SRCS=main.c stack_utils.c stack.c \
	 stack_movements.c movements.c \
	 validation.c utils.c solve.c \
	 chunk_move.c chunk_utils.c chunk_sort.c

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(SRCS) $(LIBFT)

$(LIBFT):
	make -C libft
	make -C libft bonus

clean:
	make -C libft clean

fclean:
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
