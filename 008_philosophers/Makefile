# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/09/23 17:28:58 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Default build version = release
BUILD			:=

#Compilation of the mandatory part
NAME    	= philo
SRC_DIR		= ./src/
SRC			= 00_main.c 01_print.c 02_parser.c
OBJ			= $(addprefix ${SRC_DIR}, ${SRC:.c=.o})
DEP			= $(addprefix ${SRC_DIR}, ${SRC:.c=.d})

#Compilation of the bonus part
BNS			= philo_bonus
BONUS_DIR	= ./bonus/
BONUS_SRC	= 00_main.c
BONUS_OBJ	= $(addprefix ${BONUS_DIR}, ${BONUS_SRC:.c=.o})
BONUS_DEP	= $(addprefix ${BONUS_DIR}, ${BONUS_SRC:.c=.d})

#Compilation of the files shared by the mandatory and the bonus parts
SHARED_DIR	= ./shared/
SHARED_SRC	= ft_atol.c ft_isdigit.c
SHARED_OBJ	= $(addprefix ${SHARED_DIR}, ${SHARED_SRC:.c=.o})
SHARED_DEP	= $(addprefix ${SHARED_DIR}, ${SHARED_SRC:.c=.d})

CC			= cc 
RM			= rm -rf

#Conditionnal flags depending on the building version
cflags.release	:= -Wall -Wextra -Werror -MMD -MP -pthread -Ishared
cflags.gdb		:= -g
cflags.sanitize	:= -g -fsanitize=address
CFLAGS			= ${cflags.release} ${cflags.${BUILD}}

.c.o:	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

#Mandatory rules
${NAME}:${OBJ} ${SHARED_OBJ}
		${CC} ${CFLAGS} ${OBJ} ${SHARED_OBJ} -o ${NAME}

all:    ${NAME}

#Bonus rules
${BNS}:	${BONUS_OBJ} ${SHARED_OBJ}
		${CC} ${BONUS_OBJ} ${SHARED_OBJ} -o ${BNS}

bonus:	${BNS}

#Cleaning rules
clean:
		${RM} ${OBJ} ${DEP}
		${RM} ${BONUS_OBJ} ${BONUS_DEP}
		${RM} ${SHARED_OBJ} ${SHARED_DEP}

fclean: clean
		${RM} ${NAME}
		${RM} ${BNS}

re:     fclean
		${MAKE} all

#Dependencies list
-include ${DEP} ${BONUS_DEP} ${SHARED_DEP}

.PHONY: all clean fclean re bonus
