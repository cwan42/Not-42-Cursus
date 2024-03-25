# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 10:52:57 by cwan              #+#    #+#              #
#    Updated: 2024/03/25 16:53:06 by cwan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

BNAME = pipex_bonus

SRCS =	pipex.c

BSRCS = pipex_bonus.c

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g -I ./

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

$(NAME): $(OBJS)
	@$(MAKE) -C libft bonus > /dev/null
	@$(MAKE) -C ft_printf > /dev/null
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a ./ft_printf/printf.a -o $(NAME)

$(BNAME): $(BOBJS)
	@$(MAKE) -C libft bonus > /dev/null
	@$(MAKE) -C ft_printf > /dev/null
	$(CC) $(CFLAGS) $(BOBJS) ./libft/libft.a ./ft_printf/printf.a -o $(BNAME)
	

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) ./libft/libft.a

bonus: $(BNAME)

clean:
	$(RM) $(OBJS) $(BOBJS)
	@$(MAKE) -C libft fclean > /dev/null
	@$(MAKE) -C ft_printf fclean > /dev/null
	

fclean: clean
	$(RM) $(NAME) $(BNAME)
	@$(MAKE) -C libft fclean > /dev/null
	@$(MAKE) -C ft_printf fclean > /dev/null

re: fclean all

.PHONY: all bonus clean fclean re
