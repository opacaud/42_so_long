# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opacaud <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 09:11:35 by opacaud           #+#    #+#              #
#    Updated: 2021/08/04 13:23:54 by opacaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		so_long

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror

SAN =		-fsanitize=address -g

LIB =		-L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

SRC =		so_long.c check_map_lines.c check_map_sprites.c get_next_line.c \
			get_next_line_utils.c window.c sprites.c print.c keys.c

OBJ =		${SRC:.c=.o}

all:		${NAME}

${NAME}:	${OBJ}
			${CC} ${FLAGS} ${SAN} ${LIB} ${OBJ} -o ${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o $@

clean:
			rm -f ${OBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY :	all clean fclean re
