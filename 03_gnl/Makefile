# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 17:53:19 by cwan              #+#    #+#              #
#    Updated: 2023/09/28 09:41:52 by cwan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRCS = get_next_line.c

BSRCS = get_next_line_bonus.c get_next_line_utils_bonus.c

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

bonus: $(NAME) $(BOBJS)
	ar rcs $(NAME) $(BOBJS)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
