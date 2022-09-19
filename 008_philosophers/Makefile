# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/09/19 15:29:33 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= philo
SRC_DIR		= ./src/
SRC			= 00_main.c
OBJ			= $(addprefix ${SRC_DIR}, ${SRC:.c=.o})
DEP			= $(addprefix ${SRC_DIR}, ${SRC:.c=.d})

BNS			= philo_bonus
BONUS_DIR	= ./bonus/
BONUS_SRC	= 00_main.c
BONUS_OBJ	= $(addprefix ${BONUS_DIR}, ${BONUS_SRC:.c=.o})
BONUS_DEP	= $(addprefix ${BONUS_DIR}, ${BONUS_SRC:.c=.d})

CC			= cc 
CFLAGS		= -Wall -Wextra -Werror -g -MMD -MP
RM			= rm -rf

.c.o:	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
		${CC} ${OBJS} -o ${NAME}

all:    ${NAME}

${BNS}:	${BONUS_OBJ}
		${CC} ${BONUS_OBJ} -o ${BNS}

bonus:	${BNS}

clean:
		${RM} ${OBJ} ${DEP}
		${RM} ${BONUS_OBJ} ${BONUS_DEP}

fclean: clean
		${RM} ${NAME}
		${RM} ${BNS}

re:     fclean all

-include ${DEPS}

.PHONY: all clean fclean re bonus
