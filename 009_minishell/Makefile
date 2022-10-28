# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/10/27 15:59:44 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Default build version called with make rule = release
build		:=

#Compilation of the mandatory part
NAME		= minishell

#Buildings objects
BUILTINS_DIR= src/builtins/
BUILTINS	= 00_pwd.c
SRC			+= $(addprefix ${BUILTINS_DIR}, ${BUILTINS})

EXEC_DIR	= src/execution
EXEC		= #00_exec.c
SRC			+= $(addprefix ${PIPE_DIR}, ${PIPE})

MAIN_DIR	= src/main/
MAIN		= 00_main.c
SRC			+= $(addprefix ${MAIN_DIR}, ${MAIN})

PARSING_DIR	= src/parsing/
PARSING		=
SRC			+= $(addprefix ${PARSING_DIR}, ${PARSING})

PROMPT_DIR	= src/prompt/
PROMPT		= 00_prompt.c
SRC			+= $(addprefix ${PROMPT_DIR}, ${PROMPT})

SIGNALS_DIR	= src/signals/
SIGNALS		=
SRC			+= $(addprefix ${SIGNALS_DIR}, ${SIGNALS})

OBJ			= ${SRC:.c=.o}
DEP			= ${OBJ:.o=.d}
CLIBS		= -Llibft -lft

CC			= cc 
RM			= rm -rf

#Conditionnal flags depending on the building version
cflags.release	:= -Wall -Wextra -Werror -MMD -MP -Isrc -Ilibft
cflags.gdb		:= -g
cflags.sanitize	:= -g -fsanitize=address
CFLAGS			= ${cflags.release} ${cflags.${build}}
export			CFLAGS

%.o : %.c
		${CC} ${CFLAGS} -c $< -o $@

#Mandatory rules
all:    header ${NAME}

${NAME}:${OBJ}
		${MAKE} -e -C libft
		${CC} ${CFLAGS} ${OBJ} ${CLIBS} -o ${NAME} -lreadline

header:
		cd ~/mshell/src/ ; ./hgenerator ft_minishell.h
		cd -

run:	all
		./minishell

#Bonus rules
#${BNS}:	${BONUS_OBJ} ${SHARED_OBJ}
#		${CC} ${BONUS_OBJ} ${SHARED_OBJ} -o ${BNS}
#
#bonus:	${BNS}

#Cleaning rules
clean:
		${MAKE} clean -C libft
		${RM} ${OBJ} ${DEP}

fclean: clean
		${MAKE} fclean -C libft
		${RM} ${NAME}

re:     fclean
		${MAKE} all

#Dependencies list
-include ${DEP}

.PHONY: all clean fclean re bonus header run
