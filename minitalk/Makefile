
all:
	make -C ./ft_printf
	gcc -Wall -Werror -Wextra server.c -L./ft_printf -lftprintf -o  server
	gcc -Wall -Werror -Wextra client.c -L./ft_printf -lftprintf -o  client
	./server