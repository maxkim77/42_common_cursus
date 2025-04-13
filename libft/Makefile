# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/13 15:01:37 by jeongkim          #+#    #+#              #
#    Updated: 2025/04/13 15:01:38 by jeongkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIRS = add bonus libc
SRCS = $(wildcard $(addsuffix /*.c, $(SRCS_DIRS)))
OBJS = $(SRCS:.c=.o)
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	$(RM) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
