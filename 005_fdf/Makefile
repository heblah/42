# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/06/23 17:49:18 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= fdf
SRCS		= ft_fdf/main.c ft_fdf/manage_window.c ft_fdf/handle_window.c
OBJS		= ${SRCS:.c=.o}
OMLX		= -I/usr/include -Imlx_linux -O3
CC			= cc -g
CFLAGS		= -Wall -Wextra -Werror
CMLX		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MAKE		= make
CLEAN		= make clean
FCLEAN		= make fclean
RM			= rm -rf

.c.o:
		${CC} ${CFLAGS} ${OMLX} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
		${MAKE} -C libft
		${CC} ${OBJS} ${CMLX} -o ${NAME}

all:    ${NAME}

clean:
		${RM} ${OBJS}
		${CLEAN} -C libft

fclean:    clean
		${RM} ${NAME}
		${FCLEAN} -C libft
        
re:     fclean all

.PHONY: all clean fclean re bonus
