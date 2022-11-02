# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/11/02 16:36:58 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Default build version = release letting it empty
build		:=

#Compilation of the push_swap program
NAME    	= megaphone
SRCS_DIR	= 
SRCS		= megaphone.cpp
OBJS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.o})
DEPS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.d})

CC			= c++
CLIB		= -Llibft -lft

#Rules for calling of other Makefiles
RM			= rm -rf

#Conditionnal flags depending on the building version
cflags.release	:= -Wall -Wextra -Werror -std=c++98 -MMD -MP
cflags.gdb		:= -g
cflags.sanitize	:= -g -fsanitize=address
CFLAGS			:= ${cflags.release} ${cflags.${build}}

.c.o	:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

#Mandatory rules
${NAME}:${OBJS}
		${CC} ${CFLAGS} ${OBJS} ${CLIB} -o ${NAME}

all:    ${NAME}

#Cleaning rules
clean:
		${RM} ${OBJS} ${DEPS}

fclean: clean
		${RM} ${NAME}

re:     fclean
		${MAKE} all

#Dependencies list to be included
-include ${DEPS}

.PHONY: all clean fclean re bonus
