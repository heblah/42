# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/09/15 17:40:13 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= fdf
SRCS_DIR	= ./ft_fdf/
HEADER		= ft_${NAME}.h
SRCS		= 00_main.c 01_handle_events.c 02_handle_img.c 03_parsing.c
SRCS		+= 04_parsing_utils.c 05_parsing_utils.c 06_matrix_utils.c 
SRCS		+= 07_matrix_utils.c 08_matrix_utils.c 09_put2screen.c 
SRCS		+= 10_put2screen.c 11_projections.c 12_bresenham.c
OBJS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.o})
DEPS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.d})
OMLX		= -I/usr/include -Imlx_linux
CC			= cc 
CFLAGS		= -Wall -Wextra -Werror -g -MMD -MP
CLIB		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lm -lXext -lX11
CLIB		+= -lz -Llibft -lft
MAKE		= make
CLEAN		= make clean
FCLEAN		= make fclean
RM			= rm -rf

.c.o:	
		${CC} ${CFLAGS} ${OMLX} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
		${MAKE} -C mlx_linux 
		${MAKE} -C libft
		${CC} ${CFLAGS} ${OBJS} ${CLIB} -o ${NAME}

all:    ${NAME}

bonus:	all

clean:
		${RM} ${OBJS} ${DEPS}
		${CLEAN} -C mlx_linux
		${CLEAN} -C libft

fclean: clean
		${RM} ${NAME}
		${FCLEAN} -C libft

re:     fclean all

-include ${DEPS}

.PHONY: all clean fclean re
