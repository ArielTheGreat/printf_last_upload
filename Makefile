NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c modes.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cp libft/libft.a .
	mv libft.a ${NAME}
	ar rcs $(NAME) $(OBJS)

clean:
	make -C libft fclean
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:
	fclean all

.PHONY: all clean fclean re