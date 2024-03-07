CC := cc
CFLAGS := -Wall -Wextra -g#-Werror
SRC := server.c client.c utils.c
OBJ := $(SRC:.c=.o)
SERVER := server
CLIENT := client
NAME := minitalk

all : $(NAME)

$(NAME) : $(SERVER) $(CLIENT)

$(SERVER) : server.o utils.o
	$(CC) $(CFLAGS) -o $@ server.o utils.o 

$(CLIENT) : client.o utils.o
	$(CC) $(CFLAGS) -o $@ $^

server.o : server.c minitalk.h
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY :all clean fclean re

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(SERVER) $(CLIENT)

re : fclean $(NAME)
