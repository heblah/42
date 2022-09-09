# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/09/07 21:55:53 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= push_swap
SRCS_DIR	= ./srcs/
SRCS		= 00_main.c 01_ftprint.c 02_stack_utils.c 03_stack_utils.c 04_stack_utils.c
SRCS		+= 05_moves.c 06_doublemoves.c 07_parser.c 08_sort.c 09_sort_utils.c
SRCS		+= 10_sort_utils.c 11_sort_utils.c
OBJS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.o})
DEPS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.d})
CC			= cc 
CFLAGS		= -g -Wall -Wextra -Werror -MMD -MP
CLIB		= -Llibft -lft
MAKE		= make
CLEAN		= make clean
FCLEAN		= make fclean
RM			= rm -rf

.c.o:	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
		${MAKE} -C libft
		${CC} ${OBJS} ${DEPS} ${CLIB} -o ${NAME}

all:    ${NAME}

-include ${DEPS}

clean:
		${RM} ${OBJS} ${DEPS}
		${CLEAN} -C libft

fclean: clean
		${RM} ${NAME}
		${FCLEAN} -C libft

re:     fclean all

.PHONY: all clean fclean re bonus
