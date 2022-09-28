# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 19:18:06 by hyyoo             #+#    #+#              #
#    Updated: 2022/06/05 23:20:43 by hyyoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

SRC = srcs
INC = includes
TARGET = libft.a
SOURCE = $(SRC)/ft_putchar.c $(SRC)/ft_swap.c $(SRC)/ft_putstr.c $(SRC)/ft_strlen.c $(SRC)/ft_strcmp.c
OBJS = $(SOURCE:.c=.o)

all : $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

$(TARGET) : $(OBJS)
	ar rc $@ $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all
