NAME = fractol

SRCS =	main.c \
		errors.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft.a

MLX = libmlx.a

HEADERS = fractol.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(LIBFT):
	make -c ./libft
	cp ./libft/libft.a ./

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all