# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/07/04 17:48:44 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= fdf
SRCS		= ft_fdf/main.c ft_fdf/handle_keyboard.c ft_fdf/handle_img.c
OBJS		= ${SRCS:.c=.o}
OMLX		= -I/usr/include -Imlx_linux -O3
CC			= cc -g
CFLAGS		= -Wall -Wextra -Werror 
CLIB		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
CLIB		+= -Llibft -lft
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
