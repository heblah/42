# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awallet <awallet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2023/03/15 15:33:08 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Default build version = release
build		:= san

#Compilation of the mandatory part
NAME    	= cub3D

MAIN_DIR	= ./src/main/
MAIN		= 00_main.c
SRC			+= $(addprefix ${MAIN_DIR}, ${MAIN})

PARS_DIR	= ./src/parsing/
PARS		= 00_parser.c 01_parser.c 02_parser.c 03_initplayer.c 04_moves.c
PARS		+= 
SRC			+= $(addprefix ${PARS_DIR}, ${PARS})

LIBX_DIR	= ./src/handle_minilibx/
LIBX		= 00_mlx.c 01_img.c 02_img.c 03_mouse.c
LIBX		+= 
SRC			+= $(addprefix ${LIBX_DIR}, ${LIBX})

RAY_DIR 	= ./src/raycasting/
RAY			= 00_raycasting.c 01_raycasting.c
RAY			+=
SRC			+= $(addprefix ${RAY_DIR}, ${RAY})

UTILS_DIR	= ./src/utils/
UTILS		= 00_garbage_memory.c 01_list.c 02_matrix_utils.c
UTILS		+= 
SRC			+= $(addprefix ${UTILS_DIR}, ${UTILS})

OBJ			= ${SRC:.c=.o}
DEP			= ${OBJ:.o=.d}

#Libraries
OMLX		= -I/usr/include -Imlx_linux
CLIB		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lm -lXext -lX11
CLIB		+= -lz -Llibft -lft

#Conditionnal flags depending on the building version
cflags.rls	:= -Wall -Wextra -Werror -MMD -MP -Isrc -Ilibft -Imlx_linux -Wuninitialized
cflags.gdb	:= -g3
cflags.san	:= -g3 -fsanitize=address -fsanitize=leak -fsanitize=undefined
CFLAGS		= ${cflags.rls} ${cflags.${build}}
export		CFLAGS

#Rules to other makefiles
CC			= cc
MAKE		= make
CLEAN		= make clean
FCLEAN		= make fclean
RM			= rm -rf

%.o : %.c	
		${CC} ${CFLAGS} -c $< -o $@

#Rules to compile
${NAME}:${OBJ}
		${MAKE} -C mlx_linux 
		${MAKE} -eC libft
		${CC} ${CFLAGS} ${OBJ} ${OMLX} ${CLIB} -o ${NAME}

all:    ${NAME}

bonus:	all

hgen:
	cd src; ./hgenerator ft_cube3d.h
	cd -

#Cleaning rules
clean:
		${RM} ${OBJ} ${DEP}
		${MAKE} clean -C mlx_linux
		${MAKE} clean -C libft

fclean: clean
		${RM} ${NAME}
		${MAKE} clean -C libft

re:     fclean all

#Dependencies list
-include ${DEP}

.PHONY: all clean fclean re bonus hgen
