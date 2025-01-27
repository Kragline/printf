NAME = libftprintf.a

CC = cc

CCFLAGS = -Wextra -Werror -Wall

LIBFT = ./libft

SRCS = $(LIBFT)/ft_strlen.c $(LIBFT)/ft_putstr_fd.c $(LIBFT)/ft_putchar_fd.c \
	$(LIBFT)/ft_itoa.c $(LIBFT)/ft_strdup.c ft_printf.c ft_puthex.c ft_pututils.c

OBJS := $(SRCS:%.c=%.o)

%.o: %.c Makefile $(LIBFT)/libft.h ft_printf.h
	$(CC) $(CCFLAGS) -I$(LIBFT) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
