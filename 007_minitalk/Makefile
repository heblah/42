# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/09/20 18:40:26 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Default build version = release
BUILD			:=

#Client compilation
CLI	    	= client
CLI_DIR		= ./client_srcs/
CLI_SRCS	= 00_client.c 01_parser.c
CLI_OBJS	= $(addprefix ${CLI_DIR}, ${CLI_SRCS:.c=.o})
CLI_DEPS	= $(addprefix ${CLI_DIR}, ${CLI_SRCS:.c=.d})

#Server compilation
SRV			= server
SRV_DIR		= ./server_srcs/
SRV_SRCS	= 00_server.c 01_print.c
SRV_OBJS	= $(addprefix ${SRV_DIR}, ${SRV_SRCS:.c=.o})
SRV_DEPS	= $(addprefix ${SRV_DIR}, ${SRV_SRCS:.c=.d})

CC			= cc
MAKE		= make
CLEAN		= make clean
FCLEAN		= make fclean
RM			= rm -rf

#Conditionnal flags depending on the building version
cflags.release	:= -Wall -Wextra -Werror -MMD -MP
cflags.gdb		:= -g
cflags.sanitize	:= -g -fsanitize=address
CFLAGS			= ${cflags.release} ${cflags.${BUILD}}

.c.o:	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

#Rules to compile the server and the client
all:    ${SRV} ${CLI}

bonus:	all

${CLI}:${CLI_OBJS}
		${CC} ${CFLAGS} ${CLI_OBJS} -o ${CLI}

${SRV}:${SRV_OBJS}
		${CC} ${CFLAGS} ${SRV_OBJS} -o ${SRV}

#Cleaning rules
clean:
		${RM} ${CLI_OBJS} ${CLI_DEPS}
		${RM} ${SRV_OBJS} ${SRV_DEPS}

fclean: clean
		${RM} ${CLI}
		${RM} ${SRV}

re:     fclean
		${MAKE} all

#Dependencies list
-include ${CLI_DEPS} ${SRV_DEPS}

.PHONY: all clean fclean re bonus
