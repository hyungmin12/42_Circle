NAME		= cub3D

LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		=	main.c 						\
				gnl/get_next_line.c 		\
				gnl/get_next_line_utils.c 	\
				par_src/ch_file.c			\
				par_src/ch_image.c			\
				par_src/ch_map.c 			\
				par_src/ch_rgb.c 			\
				par_src/get_element.c 		\
				par_src/get_map.c 			\
				excute_src/ft_draw.c 		\
				excute_src/ft_init.c		\
				excute_src/ft_key_event.c	\
				excute_src/ft_load.c		\
				excute_src/ft_raycasting.c	\
				excute_src/set_draw.c		\

OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror 

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		gcc -o $(NAME) $(OBJS) -Llibft -lft -lmlx -framework OpenGL -framework AppKit


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