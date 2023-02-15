NAME	= philo

SRCS = 	./main.c \
		./util.c \

OBJS 		= ${SRCS:.c=.o}

CC			= gcc #-g -fsanitize=thread
CFLAGS		= -Wall -Wextra -Werror -pthread
RM			= rm -f
NAME		= philo

all: 		${NAME}

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			@${CC} $(CFLAGS) -o $(NAME) $(OBJS)

clean:
			@${RM} ${OBJS}  
			@${RM} ${OBJS_B}

fclean: 	clean
			@${RM} ${NAME}
			@${RM} ${PHI_BONUS}

re: 		fclean all

.PHONY:		bonus all clean fclean re