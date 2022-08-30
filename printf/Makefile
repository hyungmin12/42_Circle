NAME	= libftprintf.a

SRCS	= ft_printf.c\
		  ft_putchar.c\
		  ft_puthex.c\
		  ft_putnbr.c\
		  ft_putstr.c\

CC		= cc

CFLAG	= -Wall -Wextra -Werror

OBJS	= $(SRCS:.c=.o)

INCLUDES= ./ft_printf.h

all		:	$(NAME)

.o		:	.c
			$(CC) $(CFLAG) -c $< -o $@

$(NAME)	:	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
