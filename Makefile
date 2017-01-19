# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agundry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 14:21:55 by agundry           #+#    #+#              #
#    Updated: 2017/01/15 17:34:40 by agundry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fillit

CC =	gcc

CFLAGS =	-Wall -Wextra -Werror -g

SRC =	libft/ft_strnew.c		\
		libft/ft_memalloc.c 	\
		libft/ft_strncpy.c		\
		libft/ft_strlen.c		\
		libft/ft_isalpha.c		\
		fillprint.c				\
		fillmain.c				\
		fillsolve.c				

OBJ =	$(patsubst %.c,%.o,$(SRC))

$(NAME) :
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) -I fillit.h

all	:	$(NAME)

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all
