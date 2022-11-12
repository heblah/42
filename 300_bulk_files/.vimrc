" **************************************************************************** "
"                                                                              "
"                                                         :::      ::::::::    "
"    .vimrc                                             :+:      :+:    :+:    "
"                                                     +:+ +:+         +:+      "
"    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         "
"                                                 +#+#+#+#+#+   +#+            "
"    Created: 2022/06/02 17:34:20 by halvarez          #+#    #+#              "
"    Updated: 2022/11/10 15:20:56 by halvarez         ###   ########.fr        "
"                                                                              "
" **************************************************************************** "

"vim config ====================================================================
syntax on
colorscheme default
set	number
set incsearch
set ignorecase
set	tabstop=4
set	shiftwidth=4
set	showcmd
set	autoindent
set	smartindent
set	listchars=tab:>-,trail:.,precedes:<,extends:>,eol:$
set	splitbelow
set	splitright

"42header ======================================================================
let g:user42 = 'halvarez'
let g:mail42 = 'halvarez@student.42.fr'

"remapping =====================================================================
nnoremap <C-up> 	:resize +2 <cr>
nnoremap <C-down> 	:resize -2 <cr>
nnoremap <C-right> 	:vertical resize +2 <cr>
nnoremap <C-left> 	:vertical resize -2 <cr>
nnoremap <C-t>		:vert ter <cr>
nnoremap <S-t>		:ter <cr>
nnoremap <tab>		:tabnext <cr>
nnoremap <S-tab>	:tabNext <cr>
nnoremap <S-h>		:Stdheader <cr>
nnoremap <C-e>		:Ve! <cr>
nnoremap <S-e>		:E <cr>
nnoremap <C-l> <C-w>l
nnoremap <C-k> <C-w>k
nnoremap <C-j> <C-w>j
nnoremap <C-h> <C-w>h
nnoremap <C-r> <C-w>r
nnoremap <C-x> <C-w>x
nnoremap <C-v> <C-w>v
nnoremap <S-v> <C-w>s

"fold settings =================================================================
set foldmethod=indent
set foldlevel=0
set foldnestmax=1
hi Folded ctermbg=300 "Color of folded line
"set foldclose=all "folds auto-closes when cursor in going out
