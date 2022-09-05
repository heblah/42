# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/09/05 16:26:08 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLI	    	= client
CLI_DIR		= ./client/
CLI_SRCS	= 00_client.c
SRV			= server
SRV_DIR		= ./server/
SRV_SRCS	= 00_server.c
OBJS		= $(addprefix ${CLI_DIR}, ${CLI_SRCS:.c=.o})
OBJS		+=$(addprefix ${SRV_DIR}, ${SRV_SRCS:.c=.o})
CC			= cc -g 
CFLAGS		= -Wall -Wextra -Werror
#CLIB		= -Llibft -lft
MAKE		= make
CLEAN		= make clean
FCLEAN		= make fclean
RM			= rm -rf

.c.o:	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
	#	${MAKE} -C libft
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:    ${NAME}

clean:
		${RM} ${OBJS}
	#	${CLEAN} -C libft

fclean: clean
		${RM} ${NAME}
	#	${FCLEAN} -C libft

re:     fclean all

.PHONY: all clean fclean re bonus
