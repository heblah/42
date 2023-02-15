# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awallet <awallet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2023/01/03 10:02:56 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Default build version called with make rule = release
build		:=

#Compilation of the mandatory part
NAME		= minishell

#Buildings objects
BUILTINS_DIR= src/builtins/
BUILTINS	= 00_pwd.c 01_echo.c 02_exit.c 03_env.c 04_unset.c 05_export.c
BUILTINS	+= 06_cd.c
SRC			+= $(addprefix ${BUILTINS_DIR}, ${BUILTINS})

EXEC_DIR	= src/execution/
EXEC		= 00_exec.c 01_path.c 02_execcmd.c debug.c 03_exec_builtins.c
EXEC		+= 04_exec_builtins.c
SRC			+= $(addprefix ${EXEC_DIR}, ${EXEC})

MAIN_DIR	= src/main/
MAIN		= 00_main.c
SRC			+= $(addprefix ${MAIN_DIR}, ${MAIN})

PARSING_DIR	= src/parsing/
PARSING		= 00_lexer.c 01_lexer.c 02_parser.c 03_parser.c 04_parser.c
PARSING     += 05_expansion.c
SRC			+= $(addprefix ${PARSING_DIR}, ${PARSING})

PROMPT_DIR	= src/prompt/
PROMPT		= 00_prompt.c 01_heredoc.c
SRC			+= $(addprefix ${PROMPT_DIR}, ${PROMPT})

SIGNALS_DIR	= src/signals/
SIGNALS		= 00_signals.c 
SRC			+= $(addprefix ${SIGNALS_DIR}, ${SIGNALS})

UTILS_DIR	= src/utils/
UTILS		= 00_lst_utils.c 01_garbage_memory.c 02_utils.c
SRC			+= $(addprefix ${UTILS_DIR}, ${UTILS})

G_HEADER	= hgenerator

OBJ			= ${SRC:.c=.o}
DEP			= ${OBJ:.o=.d}
CLIBS		= -Llibft -lft

CC			= cc
RM			= rm -rf

#Conditionnal flags depending on the building version
cflags.release	:= -Wall -Wextra -Werror -MMD -MP -Isrc -Ilibft
cflags.gdb		:= -g3
cflags.sanitize	:= -g3 -fsanitize=address
CFLAGS			= ${cflags.release} ${cflags.${build}}
export			CFLAGS

%.o : %.c
		${CC} ${CFLAGS} -c $< -o $@

#Mandatory rules - SUPPRIMER LA REGLE HEADER POUR NE PAS RELINK
all:    ${NAME}

${NAME}:${OBJ}
		${MAKE} -e -C libft
		${CC} ${CFLAGS} ${OBJ} ${CLIBS} -o ${NAME} -lreadline

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
