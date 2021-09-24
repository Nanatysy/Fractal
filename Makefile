NAME = fractol

BONUS = fractol_bonus

SRCS =	main.c \
		errors.c \
		mlx_start.c \
		mlx_extra.c \
		mandelbrot.c \
		julia.c \
		ft_atof.c

SRC_BONUS = main_bonus.c \
			errors.c \
			mlx_start_bonus.c \
			mlx_extra.c \
			mlx_bonus.c \
			mandelbrot.c \
			julia.c \
			ft_atof.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)

LIBFT = libft.a

MLX = libmlx.dylib

HEADERS = fractol.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(OBJS) -framework OpenGL -o $(NAME)

$(LIBFT):
	make -C ./libft
	cp ./libft/$(LIBFT) ./

$(MLX):
	make -C ./minilibX
	cp ./minilibX/$(MLX) ./

bonus: $(BONUS)

$(BONUS): $(OBJS_BONUS) $(HEADERS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(OBJS_BONUS) -framework OpenGL -o $(BONUS)

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)
	make clean -C ./libft
	make clean -C ./minilibX

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS)
	make fclean -C ./libft
	rm -rf $(LIBFT)
	rm -rf $(MLX)

re: fclean all