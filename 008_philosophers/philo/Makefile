# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/11/17 14:04:27 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Default build version called with make rule = release
build			:=

#Compilation of the mandatory part
NAME    	= philo
SRC_DIR		= ./src/
SRC			= 00_main.c 01_threads.c 02_parser.c 03_routine.c 04_monitor.c
SRC			+= 05_activity.c 06_monitor_utils.c
OBJ			= $(addprefix ${SRC_DIR}, ${SRC:.c=.o})
DEP			= $(addprefix ${SRC_DIR}, ${SRC:.c=.d})

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
cflags.sanitize	:= -g -fsanitize=thread
CFLAGS			= ${cflags.release} ${cflags.${build}}

.c.o:	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

#Mandatory rules
${NAME}:${OBJ} ${SHARED_OBJ}
		${CC} ${CFLAGS} ${OBJ} ${SHARED_OBJ} -o ${NAME}

all:    ${NAME}

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
-include ${DEP} ${SHARED_DEP}

.PHONY: all clean fclean re
