# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 14:23:40 by flcristi          #+#    #+#              #
#    Updated: 2023/05/29 15:45:56 by flcristi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = server

CLIENT = client

OBJS = 
SRCS =	client.c \
		server.c \


LIBFT_DIR = ./libft/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

CC = cc
FLAGS = -Wall -Werror -Wextra 
FLAGS_MLX = -lmlx -lX11 -Imlx -lXext

all: libft $(NAME)

objects/%.o: source/%.c includes/fractol.h
	mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $^ $(LIBFT) $(FLAGS_MLX) -o $@

libft:
	@make -C ./libft

clean:
	make clean -C ./libft
	rm -rf $(OBJS_DIR)

fclean:clean
	make fclean -C ./libft
	rm -rf  $(NAME)

re: fclean all

.PHONY: all libft clean fclean re