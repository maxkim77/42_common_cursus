# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeongkim <jeongkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/12 21:47:20 by jeongkim          #+#    #+#              #
#    Updated: 2025/07/12 21:47:20 by jeongkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a

SRCS    = ft_printf.c ft_check_type.c ft_put_c.c ft_put_d_i.c ft_put_s.c ft_put_u.c ft_put_x.c ft_put_p.c

OBJS    = ${SRCS:.c=.o}

CC      = cc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
		ar rcs ${NAME} ${OBJS}

%.o: %.c
		${CC} ${CFLAGS} -o $@ -c $<

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all