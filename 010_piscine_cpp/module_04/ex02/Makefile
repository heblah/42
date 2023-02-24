# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 14:14:06 by halvarez          #+#    #+#              #
#    Updated: 2023/02/24 17:27:56 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Default build version called with make rule = release
build		:= san

#Compilation of the mandatory part
NAME		= animals

#Buildings objects
DIR			=
FILES		= Animal.cpp Cat.cpp Dog.cpp main.cpp WrongAnimal.cpp WrongCat.cpp
FILES		+= Brain.cpp
SRC			+= $(addprefix ${DIR}, ${FILES})

OBJ			= ${SRC:.cpp=.o}
DEP			= ${OBJ:.o=.d}

CC			= c++ -std=c++98
RM			= rm -rf

#Conditionnal flags depending on building version
cflags.rls	:= -Wall -Wextra -Werror -MMD -MP -Wshadow
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
