# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agundry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 09:03:11 by agundry           #+#    #+#              #
#    Updated: 2017/02/02 18:17:11 by tbisi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

CC =	gcc

CFLAGS =	-Wall -Werror -Wextra

IFLAGS =	-I.

SRC =	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		ft_lstmap.c \
		\
		ft_isspace.c ft_cntwrd.c ft_cntdigits.c ft_putstrerror.c \
		ft_cntwrddelimc.c \
		\
		ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c \
		ft_isdigit.c ft_isalpha.c ft_atoi.c ft_strncmp.c ft_strcmp.c \
		ft_strnstr.c ft_strrchr.c ft_strchr.c ft_strlcat.c ft_strncat.c \
		ft_strcat.c ft_strncpy.c ft_strcpy.c ft_strdup.c ft_strlen.c \
		ft_memcmp.c ft_memchr.c ft_bzero.c ft_memset.c ft_strstr.c\
		ft_memccpy.c ft_memcpy.c ft_memmove.c ft_strndup.c \
		\
		ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
		ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strnequ.c

OBJ =	$(patsubst %.c,%.o,$(SRC)) 

ARCH =	ar rc $(NAME) $(OBJ)

INDX =	ranlib $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) -c $(SRC) $(IFLAGS) 
	$(ARCH)
	$(INDX)

all : $(NAME)

clean :	
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
