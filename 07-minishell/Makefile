# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 14:28:23 by cwan              #+#    #+#              #
#    Updated: 2024/05/07 14:35:17 by cwan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = minishell.c \

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g -I .

OBJS = $(SRCS:.c=.o)

$(NAME):$(OBJS) minishell.h
	@$(MAKE) -C libft > /dev/null
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BOBJS)
	@$(MAKE) -C libft clean > /dev/null

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
