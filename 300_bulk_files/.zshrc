# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    .zshrc                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 16:22:06 by halvarez          #+#    #+#              #
#    Updated: 2022/09/20 12:04:30 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

USER='halvarez'
MAIL='halvarez@student.42.fr'
export USER
export MAIL

alias ls='ls --color=auto'

alias gcc='gcc -Wall -Wextra -Werror -g'
alias cc='cc -Wall -Wextra -Werror -g'
alias valgrind='valgrind --leak-check=full'

alias makeg='make BUILD=gdb'
alias makes='make BUILD=sanitize'

alias ga='git add * -v ; git commit -am $1'
alias gaa='git add --all -v ; git commit -am $1'
alias gp='git push'
