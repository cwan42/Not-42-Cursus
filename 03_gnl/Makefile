# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 17:53:19 by cwan              #+#    #+#              #
#    Updated: 2023/09/26 18:02:53 by cwan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRCS = $(wildcard *.c)

BSRCS = \

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

BUFFER = -D BUFFER_SIZE 69

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(BUFFER) -c $< -o $@

all: $(NAME)

bonus: $(NAME) $(BOBJS)
	ar rcs $(NAME) $(BOBJS)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
