# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmansuy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 10:31:59 by gmansuy           #+#    #+#              #
#    Updated: 2022/03/27 17:07:34 by gmansuy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = rush-02 
SRC = main.c ft_putnbr_alpha.c ft_standard.c init_string.c init_structure.c print_error.c
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c-.o)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
