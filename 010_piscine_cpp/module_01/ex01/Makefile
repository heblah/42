# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 14:14:06 by halvarez          #+#    #+#              #
#    Updated: 2023/03/13 11:23:04 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Default build version called with make rule = release
build		:= san

#Compilation of the mandatory part
NAME		= horde

#Buildings objects
DIR			=
FILES		= Zombie.cpp zombieHorde.cpp main.cpp
SRC			+= $(addprefix ${DIR}, ${FILES})

OBJ			= ${SRC:.cpp=.o}
DEP			= ${OBJ:.o=.d}

CC			= c++ -std=c++98
RM			= rm -rf

#Conditionnal flags depending on the building version
cflags.rls		:= -Wall -Wextra -Werror -Wpedantic -pedantic-errors -MMD -MP
cflags.gdb		:= -g3 #-fstandalone-debug
cflags.san		:= -g3 -fsanitize=address #-fstandalone-debug
CFLAGS			= ${cflags.rls} ${cflags.${build}}
export			CFLAGS

%.o : %.cpp
		${CC} ${CFLAGS} -c $< -o $@

#Mandatory rules
all:    ${NAME}

${NAME}:${OBJ}
		${CC} ${CFLAGS} ${OBJ} -o ${NAME}


#Cleaning rules
clean:
		${RM} ${OBJ} ${DEP}

fclean: clean
		${RM} ${NAME}

re:     fclean
		${MAKE} all

run	:	all
		./${NAME}

#Dependencies list
-include ${DEP}

.PHONY: all clean fclean re bonus run
