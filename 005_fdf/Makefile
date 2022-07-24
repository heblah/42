# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/07/21 13:54:05 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= fdf
SRCS		= ./ft_fdf/00_main.c ./ft_fdf/01_handle_keyboard.c ./ft_fdf/02_handle_img.c
SRCS		+= ./ft_fdf/03_parsing.c ./ft_fdf/04_parsing_utils.c ./ft_fdf/05_parsing_utils.c
SRCS		+= ./ft_fdf/06_matrix_utils1.c 
OBJS		= ${SRCS:.c=.o}
OMLX		= -I/usr/include -Imlx_linux
CC			= cc -g 
CFLAGS		= -Wall -Wextra -Werror
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
		${CC} ${OBJS} ${CLIB} -o ${NAME}

all:    ${NAME}

clean:
		${RM} ${OBJS}
		${CLEAN} -C mlx_linux
		${CLEAN} -C libft

fclean:    clean
		${RM} ${NAME}
		${FCLEAN} -C libft
        
re:     fclean all

.PHONY: all clean fclean re bonus
