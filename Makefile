#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 11:38:09 by rduclos           #+#    #+#              #
#    Updated: 2014/01/23 21:07:27 by rduclos          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

SRC = main.c ft_tools1.c verify1.c ft_tools2.c ft_calcul.c make_move.c \
	calcul_move.c

FLAGS = -Wall -Wextra -Werror

LIB = -L libft -lft -I /usr/X11/include -I /opt/X11/include/X11 -L/usr/X11/lib -lX11 -lmlx -lXext

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAGS) -o $(NAME) $(SRC) -I. $(LIB) -I libft/

clean:
	make -C libft clean
	clear

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
	clear
