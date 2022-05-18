# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <marvin42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 15:39:44 by halvarez          #+#    #+#              #
#    Updated: 2022/05/17 17:22:45 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= libftprintf.a
SRCS_DIR	= srcs libft 
SRCS    	= 
OBJS		= $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))
MAKE		= make
CLEAN		= make clean
FCLEAN		= make fclean
RM			= rm -rf

${NAME}:
		${MAKE} bonus -C libft
		cp -r libft/${NAME} srcs/.
		${MAKE} -C srcs
		cp -r srcs/${NAME} .

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
