" **************************************************************************** "
"                                                                              "
"                                                         :::      ::::::::    "
"    .vimrc                                             :+:      :+:    :+:    "
"                                                     +:+ +:+         +:+      "
"    By: halvarez <marvin@42.fr>                    +#+  +:+       +#+         "
"                                                 +#+#+#+#+#+   +#+            "
"    Created: 2022/03/12 10:18:24 by halvarez          #+#    #+#              "
"    Updated: 2022/05/07 17:15:21 by halvarez         ###   ########.fr        "
"                                                                              "
" **************************************************************************** "

"commandes de config de vim
let g:user42 = 'halvarez'
let g:mail42 = 'halvarez@student.42.fr'
set number
set tabstop=4
set showcmd
set listchars=nbsp:¤,tab:>-,trail:¤,extends:>,precedes:<,eol:$,trail:·
set shiftwidth=4
"let g:netrw_browse_split = 2
"let g:netrw_winsize = 15
set smartindent
set autoindent

"remapping
"nnoremap w <C-w>
"nnoremap ww <C-w><C-w>
nnoremap <C-up> :resize +2<cr>
nnoremap <C-down> :resize -2<cr>
nnoremap <C-right> :vertical resize +2<cr>
nnoremap <C-left> :vertical resize -2<cr>
