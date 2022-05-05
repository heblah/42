# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 15:39:44 by halvarez          #+#    #+#              #
#    Updated: 2022/05/05 15:43:34 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= libft.a
SRCS    	= ft_atoi.c     ft_isascii.c  ft_memcmp.c      ft_putendl_fd.c  ft_strdup.c    ft_strlen.c   ft_strtrim.c \
	ft_bzero.c    ft_isdigit.c  ft_memcpy.c      ft_putnbr_fd.c   ft_striteri.c  ft_strmapi.c  ft_substr.c \
	ft_calloc.c   ft_isprint.c  ft_memmove.c     ft_putstr_fd.c   ft_strjoin.c   ft_strncmp.c  ft_tolower.c \
	ft_isalnum.c  ft_itoa.c     ft_memset.c      ft_split.c       ft_strlcat.c   ft_strnstr.c  ft_toupper.c \
	ft_isalpha.c  ft_memchr.c   ft_putchar_fd.c  ft_strchr.c      ft_strlcpy.c   ft_strrchr.c
OBJS		= ${SRCS:.c=.o}
BONUS_C		= 
BONUS_O		= ${BONUS_C:.c=.o}
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

.c.o:
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
		@ar -rcs ${NAME} ${OBJS}

all:    ${NAME}

bonus:    all
		@${CC} ${CFLAGS} -c ${BONUS_C}
		@ar -rcs ${NAME} ${BONUS_O}

clean:
		@${RM} ${OBJS}
		@${RM} ${BONUS_O}

fclean:    clean
		@${RM} ${NAME}
        
re:     fclean all

.PHONY: all clean fclean re bonus
