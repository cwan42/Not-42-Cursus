# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 16:33:49 by cwan              #+#    #+#              #
#    Updated: 2024/07/06 16:37:12 by cwan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror -g

SRCS = utils.c philo.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) philo.h
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

test: $(OBJS)
	$(CC) $(FLAGS) -fsanitize=thread $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
