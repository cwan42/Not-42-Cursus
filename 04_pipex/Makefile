# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 10:52:57 by cwan              #+#    #+#              #
#    Updated: 2024/02/23 13:43:00 by cwan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =	pipex.c

BSRCS = pipexbonus.c

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g -I ./

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

$(NAME): $(OBJS)
	@$(MAKE) -C libft bonus > /dev/null
	@$(MAKE) -C ft_printf > /dev/null
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a ./ft_printf/printf.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(NAME) $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) ./libft/libft.a ./ft_printf/printf.a -o $(NAME)
#still relinks

clean:
	$(RM) $(OBJS) $(BOBJS)
	@$(MAKE) -C libft fclean > /dev/null
	@$(MAKE) -C ft_printf fclean > /dev/null
	

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C libft fclean > /dev/null
	@$(MAKE) -C ft_printf fclean > /dev/null

re: fclean all

.PHONY: all bonus clean fclean re
