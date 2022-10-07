# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    .zshrc                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 16:22:06 by halvarez          #+#    #+#              #
#    Updated: 2022/10/07 09:36:19 by halvarez         ###   ########.fr        #
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

#Compilation options
alias cc='cc -Wall -Wextra -Werror -g'
alias gcc='gcc -Wall -Wextra -Werror -g'
alias makec='make clean'
alias makef='make fclean'
alias makeg='make build=gdb'
alias makes='make build=sanitize'

#Debugging
alias gdb='gdb'
alias gda='gdb --arg'

#Git alial
alias ga='git add * -v ; git commit -am $1'
alias gaa='git add --all -v ; git commit -am $1'
alias gp='git push'
