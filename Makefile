NAME = libftprintf.a

CC = cc

CCFLAGS = -Wextra -Werror -Wall

LIBFT = ./libft

SRCS = ft_printf.c ft_puthex.c ft_pututils.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c Makefile ft_printf.h
	$(CC) $(CCFLAGS) -I$(LIBFT) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
