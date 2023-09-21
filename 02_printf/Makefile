# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 10:20:30 by cwan              #+#    #+#              #
#    Updated: 2023/09/21 11:06:21 by cwan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printc.c ft_prints.c ft_printp.c ft_printd.c \

BSRCS = \

TEST = Tester.c \

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

TESTS = $(TEST:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(NAME) $(BOBJS)
	ar rcs $(NAME) $(BOBJS)

clean:
	$(RM) $(OBJS) $(BOBJS) $(TESTS) test

fclean: clean
	$(RM) $(NAME)

test: $(NAME) $(TESTS)
	$(CC) $(TESTS) -L -l $(NAME) -o test

re: fclean all

.PHONY: all clean fclean re
