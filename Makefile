NAME = fractol

SRCS =	main.c \
		errors.c \
		mlx_start.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft.a

MLX = libmlx.dylib

HEADERS = fractol.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(OBJS) -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	make -C ./libft
	cp ./libft/$(LIBFT) ./

$(MLX):
	make -C ./minilibX
	cp ./minilibX/$(MLX) ./

clean:
	rm -rf $(OBJS)
	make clean -C ./libft
	make clean -C ./minilibX

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft
	rm -rf $(LIBFT)
	rm -rf $(MLX)

re: fclean all