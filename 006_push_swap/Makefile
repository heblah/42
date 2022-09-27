# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/09/26 16:33:18 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Default build version = release letting it empty
BUILD		:=

#Compilation of the push_swap program
NAME    	= push_swap
SRCS_DIR	= ./srcs/
SRCS		= 00_main.c 01_ftprint.c 02_stack_utils.c 03_stack_utils.c 04_stack_utils.c
SRCS		+= 05_moves.c 06_doublemoves.c 07_parser.c 08_sort.c 09_sort_utils.c
SRCS		+= 10_sort_utils.c 11_sort_utils.c
OBJS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.o})
DEPS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.d})

CC			= cc
CLIB		= -Llibft -lft

#Rules for calling of other Makefiles
RM			= rm -rf

#Conditionnal flags depending on the building version
cflags.release	:= -Wall -Wextra -Werror -MMD -MP
cflags.gdb		:= -g
cflags.sanitize	:= -g -fsanitize=address
CFLAGS			:= ${cflags.release} ${cflags.${BUILD}}

.c.o	:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

#Mandatory rules
${NAME}:${OBJS}
		${MAKE} -C libft
		${CC} ${CFLAGS} ${OBJS} ${CLIB} -o ${NAME}

all:    ${NAME}

#Cleaning rules
clean:
		${RM} ${OBJS} ${DEPS}
		${MAKE} clean -C libft

fclean: clean
		${RM} ${NAME}
		${MAKE} fclean -C libft

re:     fclean
		${MAKE} all

#Dependencies list to be included
-include ${DEPS}

.PHONY: all clean fclean re bonus
