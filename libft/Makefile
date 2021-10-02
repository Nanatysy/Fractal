NAME = libft.a
SRCC =	ft_strncmp.c \
		ft_atoi.c \
		ft_strlen.c \
		ft_isdigit.c
SRCO = $(SRCC:%.c=%.o)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCO)
	ar rc $(NAME) $^

%.o: %.c libft.h
	gcc $(FLAGS) -c $<

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all