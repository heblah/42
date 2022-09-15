# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/09/15 17:52:09 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLI	    	= client
CLI_DIR		= ./client_srcs/
CLI_SRCS	= 00_client.c 01_parser.c
CLI_OBJS	= $(addprefix ${CLI_DIR}, ${CLI_SRCS:.c=.o})
CLI_DEPS	= $(addprefix ${CLI_DIR}, ${CLI_SRCS:.c=.d})
SRV			= server
SRV_DIR		= ./server_srcs/
SRV_SRCS	= 00_server.c 01_print.c
SRV_OBJS	= $(addprefix ${SRV_DIR}, ${SRV_SRCS:.c=.o})
SRV_DEPS	= $(addprefix ${SRV_DIR}, ${SRV_SRCS:.c=.d})
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -MMD -MP
MAKE		= make
CLEAN		= make clean
FCLEAN		= make fclean
RM			= rm -rf

all:    ${SRV} ${CLI}

.c.o:	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${CLI}:${CLI_OBJS}
		${CC} ${CFLAGS} ${CLI_OBJS} -o ${CLI}

${SRV}:${SRV_OBJS}
		${CC} ${CFLAGS} ${SRV_OBJS} -o ${SRV}

clean:
		${RM} ${CLI_OBJS} ${CLI_DEPS}
		${RM} ${SRV_OBJS} ${SRV_DEPS}

fclean: clean
		${RM} ${CLI}
		${RM} ${SRV}

re:     fclean all

bonus:	all

-include ${CLI_DEPS} ${SRV_DEPS}

.PHONY: all clean fclean re bonus
