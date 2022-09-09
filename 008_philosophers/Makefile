# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/09/09 16:49:57 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= philo
SRCS_DIR	= ./srcs/
SRCS		= 00_main.c
OBJS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.o})
DEPS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.d})
BONUS_DIR	= ./bonus/
BONUS_SRCS	= 00_main.c
BONUS_OBJS	= $(addprefix ${BONUS_DIR}, ${BONUS_SRCS:.c=.o})
BONUS_DEPS	= $(addprefix ${BONUS_DIR}, ${BONUS_SRCS:.c=.d})
CC			= cc 
CFLAGS		= -Wall -Wextra -Werror -g -MMD -MP
RM			= rm -rf

.c.o:	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
		${CC} ${OBJS} -o ${NAME}

all:    ${NAME}

bonus:	fclean ${BONUS_OBJS}
		${CC} ${BONUS_OBJS} -o ${NAME}

clean:
		${RM} ${OBJS} ${DEPS}
		${RM} ${BONUS_OBJS} ${BONUS_DEPS}

fclean: clean
		${RM} ${NAME}

re:     fclean all

-include ${DEPS}

.PHONY: all clean fclean re bonus
