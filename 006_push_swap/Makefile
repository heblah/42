# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/08/26 15:24:29 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= push_swap
SRCS_DIR	= ./srcs/
SRCS		= 00_main.c 01_ftprint.c 02_stack_utils.c 03_stack_utils.c 04_stack_utils.c
SRCS		+= 05_moves.c 06_doublemoves.c 07_parser.c 08_sort.c 09_sort_utils.c
SRCS		+= #10_sort_utils.c
OBJS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.o})
CC			= cc -g 
CFLAGS		= -Wall -Wextra -Werror
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
