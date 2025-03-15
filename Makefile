# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oait-h-m <oait-h-m@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 01:58:15 by oait-h-m          #+#    #+#              #
#    Updated: 2025/03/11 01:58:29 by oait-h-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server 
NAME_CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

CC = cc
FLAGS = -Wall -Wextra -Werror

SRC_SER = src/functions.c src/server.c
SRC_CLI = src/functions.c src/client.c

BONUS_SER = bonus/functions_bonus.c bonus/server_bonus.c
BONUS_CLI = bonus/functions_bonus.c bonus/client_bonus.c

OBJ_SER = $(SRC_SER:.c=.o)
OBJ_CLI = $(SRC_CLI:.c=.o)

OBJ_B_SER = $(BONUS_SER:.c=.o)
OBJ_B_CLI = $(BONUS_CLI:.c=.o)

RM = rm -rf

all: $(NAME_SERVER) $(NAME_CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(NAME_SERVER): $(OBJ_SER)
	$(CC) $(FLAGS) $(OBJ_SER) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLI)
	$(CC) $(FLAGS) $(OBJ_CLI) -o $(NAME_CLIENT)


$(SERVER_BONUS): $(OBJ_B_SER)
	$(CC) $(FLAGS) $(OBJ_B_SER) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJ_B_CLI)
	$(CC) $(FLAGS) $(OBJ_B_CLI) -o $(CLIENT_BONUS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_SER) $(OBJ_CLI) $(OBJ_B_SER) $(OBJ_B_CLI)

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all bonus

.PHONY: all bonus clean fclean re

.SECONDARY:
