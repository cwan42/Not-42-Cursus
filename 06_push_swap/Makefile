# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 16:42:25 by cwan              #+#    #+#              #
#    Updated: 2024/03/24 06:50:56 by cwan42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = 	srcs/ops_push.c srcs/ops_swap.c srcs/ops_rotate.c srcs/ops_rrotate.c \
		srcs/stackfns.c srcs/stackutils.c srcs/stackutils2.c srcs/utils.c \
		srcs/01-Inputvalidatn.c srcs/02-procif3.c \
		push_swap.c

BSRCS = \

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g -I .

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

$(NAME):$(OBJS) push_swap.h
	@$(MAKE) -C libft > /dev/null
	@$(MAKE) -C ft_printf > /dev/null
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a ./ft_printf/printf.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(NAME) $(BOBJS)
	$(CC) $(CFLAGS) $(NAME) $(BOBJS) -o $(NAME)

clean: 
	$(RM) $(OBJS) $(BOBJS)
	@$(MAKE) -C libft clean > /dev/null
	@$(MAKE) -C ft_printf clean > /dev/null

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C libft fclean > /dev/null
	@$(MAKE) -C ft_printf fclean > /dev/null

re: fclean all

.PHONY: all bonus clean fclean re
