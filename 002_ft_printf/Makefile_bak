# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <marvin42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 15:39:44 by halvarez          #+#    #+#              #
#    Updated: 2022/05/19 11:25:59 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= libftprintf.a
LIBFT		= libft/libft.a
SRCS    	= srcs/ft_printf.c srcs/ft_puthex.c srcs/ft_putnbr.c srcs/ft_puttxt.c
OBJS		= ${SRCS:.c=.o}
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MAKE		= make
CLEAN		= make clean
FCLEAN		= make fclean
RM			= rm -rf

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
		${MAKE} bonus -C libft
		cp -r ${LIBFT} ${NAME}
		ar -rcs ${NAME} ${OBJS}

all:    ${NAME}

clean:
		${CLEAN} -C libft
		${CLEAN} -C srcs

fclean:    clean
		${FCLEAN} -C libft
		${FCLEAN} -C srcs
		${RM} ${NAME}
        
re:     fclean all

.PHONY: all clean fclean re bonus
