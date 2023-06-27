# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/10/11 18:22:30 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= libft.a
SUBDIR		= libft/ gnl/ printf/

LIBFT_DIR	= libft/
LIBFT		= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c
LIBFT		+=ft_isdigit.c ft_itoa.c ft_memcmp.c ft_memcpy.c ft_memmove.c
LIBFT		+=ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c
LIBFT		+=ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c
LIBFT		+=ft_strlcpy.c ft_strlen.c ft_strcmp.c ft_strncmp.c ft_strnstr.c
LIBFT		+=ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

PRINTF_DIR	+= printf/
PRINTF		= ft_printf.c ft_puthex.c ft_putnbr.c ft_puttxt.c

GNL_DIR		+= gnl/
GNL			= get_next_line_bonus.c get_next_line_utils_bonus.c

CFLS		= $(addprefix ${LIBFT_DIR}, ${LIBFT})
CFLS		+= $(addprefix ${PRINTF_DIR}, ${PRINTF})
CFLS		+= $(addprefix ${GNL_DIR}, ${GNL})

OBJ_DIR		= ${CURDIR}/obj/
OBJS		= $(addprefix ${OBJ_DIR}, ${CFLS:.c=.o})
DEPS		= $(OBJS:.o=.d)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD -MP
RM			= rm -rf

${OBJ_DIR}%.o : %.c
		${CC} ${CFLAGS} -c $< -o $@

${NAME}:mdir ${OBJS}
		ar -rcs ${NAME} ${OBJS}

#rules
all:   	${NAME}

mdir:
		mkdir -p $(addprefix ${OBJ_DIR}, ${SUBDIR})

clean:
		${RM} ${OBJS} ${DEPS}
		${RM} ${OBJ_DIR}

fclean:    clean
		${RM} ${NAME}

re:     fclean all

-include ${DEPS}

.PHONY: all clean fclean re bonus
