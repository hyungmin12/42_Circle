CC = gcc
CFLAG = -Wall -Werror -Wextra
 
TARGET = do-op
 
SOURCE = ft_do.c main.c ft_check.c
INCLUDE = ft.h
OBJS = $(SOURCE:.c=.o)
 
all : $(TARGET)
 
$(TARGET) : $(OBJS)
	$(CC) $(CFLAG) -o $(TARGET) $(SOURCE)
 
clean :
	rm -f $(OBJS)
 
fclean : clean
	rm -f $(TARGET)
 
re : fclean all
