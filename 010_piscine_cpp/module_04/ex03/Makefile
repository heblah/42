# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 14:14:06 by halvarez          #+#    #+#              #
#    Updated: 2023/03/03 11:24:09 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Default build version called with make rule = release
build		:= san

#Compilation of the mandatory part
NAME		= magic

#Buildings objects
DIR			=
FILES		= main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp 
SRC			+= $(addprefix ${DIR}, ${FILES})

OBJ			= ${SRC:.cpp=.o}
DEP			= ${OBJ:.o=.d}

CC			= c++ -Wshadow -std=c++98
RM			= rm -rf

#Conditionnal flags depending on building version
cflags.rls	:= -Wall -Wextra -Werror -Wpedantic -pedantic-errors -MMD -MP
cflags.gdb	:= -g3 #-fstandalone-debug
cflags.san	:= -g3 -fsanitize=address #-fstandalone-debug 
CFLAGS		= ${cflags.rls} ${cflags.${build}}
export		CFLAGS

%.o : %.cpp
		${CC} ${CFLAGS} -c $< -o $@

#Mandatory rules
all:    ${NAME}

${NAME}:${OBJ}
		${CC} ${CFLAGS} ${OBJ} -o ${NAME}

#Execution rule
run:	all
		./${NAME}

#Cleaning rules
clean:
		${RM} ${OBJ} ${DEP}

fclean: clean
		${RM} ${NAME}

re:     fclean
		${MAKE} all

#Dependencies list
-include ${DEP}

.PHONY: all clean fclean re bonus
