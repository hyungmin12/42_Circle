# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 19:25:26 by hyyoo             #+#    #+#              #
#    Updated: 2022/06/07 03:15:52 by hyyoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAG = -Wall -Werror -Wextra

TARGET = do-op

SOURCE = op.c util.c main.c
INCLUDE = ft_head.h

OBJS = $(SOURCE:.c=.o)

all : $(TARGET)

%.c : %.o
	$(CC) $(CFLAG) -c $<

$(TARGET) : $(OBJS)
	$(CC) $(CFLAG) -o $@ $^ -I $(INCLUDE)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all
