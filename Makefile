# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 14:23:40 by flcristi          #+#    #+#              #
#    Updated: 2023/05/29 20:44:19 by flcristi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = 		server
SRC_SERVER =	server.c
OBJ_SERVER =	$(SRC_SERVER:%.c=%.o)

CLIENT =		client
SRCS_CLIENT =	client.c
OBJ_CLIENT =	$(SRC_CLIENT:%.c=%.o)

LIBFT_DIR = libft/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

CC = cc
FLAGS = -Wall -Werror -Wextra -g3

all: libft $(NAME)

%.o: %.c 
	$(CC) $(FLAGS) -c $< -o $@ -I.

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	$(CC) $(FLAGS) $(SRC_SERVER) $^ $(LIBFT) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(FLAGS) $(SRC_CLIENT) $^ $(LIBFT) -o $(CLIENT)

libft:
	@make -C ./libft

clean:
	make clean -C ./libft
	rm -rf $(OBJS)

fclean:clean
	make fclean -C ./libft
	rm -rf  $(NAME)

re: fclean all

.PHONY: all libft clean fclean re