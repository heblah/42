# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <marvin42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 15:39:44 by halvarez          #+#    #+#              #
#    Updated: 2022/05/28 11:25:56 by hans             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= gnl.out
BUF			= 100
SRCS    	= get_next_line.c get_next_line_utils.c main.c
OBJS		= ${SRCS:.c=.o}
BONUS_O		= ${BONUS_C:.c=.o}
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g -D BUFFER_SIZE=${BUF}
RM			= rm -rf

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${SRCS}

all:    ${NAME}

clean:
		${RM} ${OBJS}
		${RM} ${BONUS_O}

fclean:    clean
		${RM} ${NAME}
        
re:     fclean all

.PHONY: all clean fclean re bonus
