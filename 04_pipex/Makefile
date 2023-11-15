# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 10:52:57 by cwan              #+#    #+#              #
#    Updated: 2023/11/15 10:59:33 by cwan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a

SRCS = \

BSRCS = \

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
