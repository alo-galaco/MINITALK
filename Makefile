# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 14:23:40 by flcristi          #+#    #+#              #
#    Updated: 2023/05/29 21:21:10 by flcristi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = 		server
SRC_SERVER =	server.c
OBJ_SERVER =	$(SRC_SERVER:.c=.o)

CLIENT =		client
SRC_CLIENT =	client.c
OBJ_CLIENT =	$(SRC_CLIENT:.c=.o)

LIBFT_DIR = libft/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

CC = cc
FLAGS = -Wall -Werror -Wextra

all: libft $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	$(CC) $(FLAGS) $^ $(LIBFT) -o $@

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(FLAGS) $^ $(LIBFT) -o $@

libft:
	@make -C ./libft

clean:
	make clean -C ./libft
	rm -rf $(OBJ_SERVER) $(OBJ_CLIENT)

fclean:clean
	make fclean -C ./libft
	rm -rf  $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all libft clean fclean re