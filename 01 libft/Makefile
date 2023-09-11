# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 14:07:59 by cwan              #+#    #+#              #
#    Updated: 2023/09/11 15:31:51 by cwan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = \
	ft_isascii.c ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_isprint.c \
	ft_toupper.c ft_tolower.c ft_atoi.c \
	ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_strnstr.c \
	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_calloc.c ft_strdup.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
HEADERS = ./

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I $(HEADERS)

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) Test1 Test3

re: fclean all

test:
	$(CC) $(CFLAGS) -o Test1 Tester1.c -L -l $(NAME)
	$(CC) $(CFLAGS) -o Test3 Tester3.c -L -l $(NAME)

.PHONY: all clean fclean re
