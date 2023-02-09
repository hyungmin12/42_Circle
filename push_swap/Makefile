NAME		= push_swap
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		=	push_swap.c \
				./srcs/parsing.c \
				./srcs/arr.c \
				./srcs/utils.c \
				./srcs/utils2.c \
				./srcs/ft_init_and_free.c \
				./srcs/ft_add_and_del.c \
				./srcs/ft_add_and_del2.c \
				./srcs/ft_pp_rr.c \
				./srcs/ft_rrr.c \
				./srcs/ft_ss.c \
				./srcs/ft_sort_2_3_4.c \
				./srcs/ft_sort_utils.c \
				./srcs/ft_sort.c \
			
OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror -g

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		gcc -o $(NAME) $(OBJS) -Llibft -lft

%.o			:	%.c
		gcc $(FLAGS) -c $^ -I./ -o $@


clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re