# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    .zshrc                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 16:22:06 by halvarez          #+#    #+#              #
#    Updated: 2022/11/09 13:13:11 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Prompt config
# Load version control information
autoload -Uz vcs_info
precmd() { vcs_info }

# Format the vcs_info_msg_0_ variable
zstyle ':vcs_info:git:*' formats ' %F{001}[%b]%f'
 
# Set up the prompt (with git branch name)
setopt PROMPT_SUBST
PROMPT='%m:%~/${vcs_info_msg_0_} > '
# Enable substitution in the prompt.
setopt prompt_subst

# Config for prompt. PS1 synonym.
#PROMPT='%m:%~/${cvs_info_msg_0_} > '

#42 header options
USER='halvarez'
MAIL='halvarez@student.42.fr'
export USER
export MAIL

#Colors in ls
alias ls='ls --color=auto'

#Compilation options
alias cc='cc -Wall -Wextra -Werror -g3'
alias gcc='gcc -Wall -Wextra -Werror -g3'
alias makeb='make bonus'
alias makec='make clean'
alias makef='make fclean'
alias makeg='make build=gdb'
alias makes='make build=sanitize'
alias hmshell='cd ~/mshell/src; ./hgenerator ft_minishell.h; cd -'

#Debugging
alias gdb='gdb'
alias gda='gdb --arg'

#Git alias
alias ga='git add * -v ; git commit -am $1'
alias gaa='git add --all -v ; git commit -am $1'
alias gp='git push'
