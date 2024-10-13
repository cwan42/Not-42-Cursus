#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbandara <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 13:33:09 by cbandara          #+#    #+#              #
#    Updated: 2024/09/06 18:42:26 by cwan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

FLAGS = -Wall -Wextra -Werror -g -I . -Iinclude

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

SRCS =	srcs/01-initcmdtab.c srcs/02-strproc.c srcs/02-strproc2.c \
		srcs/03-initarrexpander.c srcs/04-quoteexpforreal.c\
		srcs/builtins/cd.c srcs/builtins/echo.c srcs/builtins/env.c \
		srcs/builtins/exit.c srcs/builtins/export.c srcs/builtins/pwd.c \
		srcs/builtins/unset.c \
		srcs/signals.c srcs/signals_heredoc.c srcs/modifiedsplit.c \
		srcs/minishell.c srcs/utils.c \
		srcs/executer.c srcs/executer2.c srcs/executer3.c srcs/executer4.c \
		srcs/exec.c srcs/exec2.c srcs/exec3.c srcs/heredoc.c srcs/errmsg.c \
		srcs/minishell_utils.c srcs/inputcheck1.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -lreadline -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -c -o $@ $<
	
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
