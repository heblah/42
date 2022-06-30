# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <marvin42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 15:39:44 by halvarez          #+#    #+#              #
#    Updated: 2022/05/19 11:14:08 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= libft.a
SRCS_DIR	=
SRCS    	= ft_printf.c ft_puthex.c ft_putnbr.c ft_puttxt.c
OBJS		= ${SRCS:.c=.o}
#OBJS		= $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
		ar -rcs ${NAME} ${OBJS}

all:    ${NAME}

clean:
		${RM} ${OBJS}
		${RM} ${BONUS_O}

fclean:    clean
		${RM} ${NAME}
        
re:     fclean all

.PHONY: all clean fclean re bonus
