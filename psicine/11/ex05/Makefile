TARGET = do-op
SRC = op.c util.c main.c

all: $(TARGET)

$(TARGET):
	gcc -Wall -Werror -Wextra -o $(TARGET) $(SRC)

fclean:
	rm -f $(TARGET)

clean:
	rm -f *.o

re: fclean all
