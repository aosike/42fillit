# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agundry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 14:21:55 by agundry           #+#    #+#              #
#    Updated: 2017/02/07 14:17:02 by agundry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fillit

CC = 	gcc

CFLAGS =	-Wall -Wextra -Werror

SRC =	fillmain.c				\
		fillsolve.c				\
		fillcheck.c				\
		fillvalid.c				\

OBJ =	$(patsubst %.c,%.o,$(SRC))

$(NAME) :	
			make -C libft/ fclean && make -C libft/
			$(CC) $(CFLAGS) -c $(SRC) -I libft/ fillit.h
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

all	:	$(NAME)

clean	:
	make -C libft/ fclean
	/bin/rm -f $(OBJ)

fclean	:	clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re	:	fclean all
