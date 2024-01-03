# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 16:42:25 by cwan              #+#    #+#              #
#    Updated: 2024/01/03 10:45:33 by cwan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = \
		push_swap.c stackfunctions.c cmd_swap.c\

BSRCS = \

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g -I ./

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

$(NAME):$(OBJS)
	@$(MAKE) -C libft bonus > /dev/null
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
