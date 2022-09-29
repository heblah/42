# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    .zshrc                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 16:22:06 by halvarez          #+#    #+#              #
#    Updated: 2022/09/29 15:18:10 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Prompt config
#PROMPT='%m:%1~ %n%#'
PROMPT='%m:%~ > '

#42 header options
USER='halvarez'
MAIL='halvarez@student.42.fr'
export USER
export MAIL

#Colors in ls
alias ls='ls --color=auto'

#Compilation with flags
alias gcc='gcc -Wall -Wextra -Werror -g'
alias cc='cc -Wall -Wextra -Werror -g'

#Compilation options for Makefiles
alias makeg='make BUILD=gdb'
alias makes='make BUILD=sanitize'

#Git alial
alias ga='git add * -v ; git commit -am $1'
alias gaa='git add --all -v ; git commit -am $1'
alias gp='git push'
