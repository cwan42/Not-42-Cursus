# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 10:52:57 by cwan              #+#    #+#              #
#    Updated: 2023/12/01 16:45:40 by cwan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
#NAME = pipex.a

SRCS = \
		pipex.c\

BSRCS = \

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g -I ./

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

$(NAME): $(OBJS)
	@$(MAKE) -C libft bonus > /dev/null
	@$(MAKE) -C ft_printf > /dev/null
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a ./ft_printf/printf.a -o $(NAME)
#	ar rcs $(NAME) ./libft/libft.a ./ft_printf/printf.a $(OBJS)

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
