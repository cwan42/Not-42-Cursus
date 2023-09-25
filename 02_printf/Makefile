# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 10:20:30 by cwan              #+#    #+#              #
#    Updated: 2023/09/25 15:06:15 by cwan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printp.c ft_printf.c \

BSRCS = \

TEST = Tester.c \

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I ./libft

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

TESTS = $(TEST:.c=.o)

$(NAME): $(OBJS)
	@$(MAKE) -C libft
	ar rcs $(NAME) $(OBJS) ./libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(NAME) $(BOBJS)
	ar rcs $(NAME) $(BOBJS)

clean:
	$(RM) $(OBJS) $(BOBJS) $(TESTS) test
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

test: $(NAME) $(TESTS)
	$(CC) $(TESTS) -I./libft -L -l $(NAME) -L./libft -lft -o test

re: fclean all

.PHONY: all clean fclean re
