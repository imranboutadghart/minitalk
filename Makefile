CC = gcc
CFLAGS = -Wall -Wextra
SERVER = server
CLIENT = client
NAME = minitalk


$(NAME) : $(SERVER) $(CLIENT)

$(SERVER) : server.c utils.c
	$(CC) $(CFLAGS) -o $@ $^

$(CLIENT) : client.c utils.c
	$(CC) $(CFLAGS) -o $@ $^

.PHONY :all clean fclean re

all : $(name)

clean :
	rm -rf $(SERVER) $(CLIENT)

fclean : clean

re : fclean $(NAME)
