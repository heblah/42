# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/08/25 17:42:44 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= push_swap
SRCS_DIR	= ./srcs/
SRCS		= 00_main.c 01_ftprint.c 02_list_utils.c 03_list_utils.c 04_moves.c
SRCS		+= 05_doublemoves.c 06_parser.c# 08_check.c 09_sort.c 10_sort_utils.c
OBJS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.o})
CC			= cc -g 
CFLAGS		= -Wall -Wextra -Werror -MMD -MP
CLIB		= -Llibft -lft
MAKE		= make
CLEAN		= make clean
FCLEAN		= make fclean
RM			= rm -rf

.c.o:	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
		${MAKE} -C libft
		${CC} ${OBJS} ${CLIB} -o ${NAME}

all:    ${NAME}

clean:
		${RM} ${OBJS}
		${CLEAN} -C libft

fclean: clean
		${RM} ${NAME}
		${FCLEAN} -C libft

re:     fclean all

.PHONY: all clean fclean re bonus
