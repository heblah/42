# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/09/21 21:07:07 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Default build version = release
BUILD			:=

#Compilation of the mandatory part
NAME    	= fdf
SRCS_DIR	= ./ft_fdf/
SRCS		= 00_main.c 01_handle_events.c 02_handle_img.c 03_parsing.c
SRCS		+= 04_parsing_utils.c 05_parsing_utils.c 06_matrix_utils.c 
SRCS		+= 07_matrix_utils.c 08_matrix_utils.c 09_put2screen.c 
SRCS		+= 10_put2screen.c 11_projections.c 12_bresenham.c
OBJS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.o})
DEPS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.d})

#Libraries
OMLX		= -I/usr/include -Imlx_linux
CLIB		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lm -lXext -lX11
CLIB		+= -lz -Llibft -lft

#Conditionnal flags depending on the building version
cflags.release	:= -Wall -Wextra -Werror -MMD -MP
cflags.gdb		:= -g
cflags.sanitize	:= -g -fsanitize=address
CFLAGS			= ${cflags.release} ${cflags.${BUILD}}

#Rules to other makefiles
CC			= cc
MAKE		= make
CLEAN		= make clean
FCLEAN		= make fclean
RM			= rm -rf

.c.o:	
		${CC} ${CFLAGS} ${OMLX} -c $< -o ${<:.c=.o}

#Rules to compile
${NAME}:${OBJS}
		${MAKE} -C mlx_linux 
		${MAKE} -C libft
		${CC} ${CFLAGS} ${OBJS} ${CLIB} -o ${NAME}

all:    ${NAME}

bonus:	all
love:	
		@echo -e "\nlove you ouech ouech\n"

#Cleaning rules
clean:
		${RM} ${OBJS} ${DEPS}
		${CLEAN} -C mlx_linux
		${CLEAN} -C libft

fclean: clean
		${RM} ${NAME}
		${FCLEAN} -C libft

re:     fclean all

#Dependencies list
-include ${DEPS}

.PHONY: all clean fclean re
