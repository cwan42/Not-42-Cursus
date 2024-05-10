# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 14:28:23 by cwan              #+#    #+#              #
#    Updated: 2024/05/10 12:41:51 by cwan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = srcs/builtins/env.c srcs/builtins/pwd.c \
		minishell.c \

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g -I .

OBJS = $(SRCS:.c=.o)

$(NAME):$(OBJS) minishell.h
	@$(MAKE) -C libft bonus > /dev/null
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -lreadline -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BOBJS)
	@$(MAKE) -C libft clean > /dev/null

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C libft fclean > /dev/null

re: fclean all

.PHONY: all clean fclean re
