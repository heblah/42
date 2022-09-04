" **************************************************************************** "
"                                                                              "
"                                                         :::      ::::::::    "
"    .vimrc                                             :+:      :+:    :+:    "
"                                                     +:+ +:+         +:+      "
"    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         "
"                                                 +#+#+#+#+#+   +#+            "
"    Created: 2022/06/02 17:34:20 by halvarez          #+#    #+#              "
"    Updated: 2022/08/11 10:04:55 by halvarez         ###   ########.fr        "
"                                                                              "
" **************************************************************************** "

"vim config ====================================================================
:syntax on
color default
set	number
set	tabstop=4
set	shiftwidth=4
set	showcmd
set	autoindent
set	listchars=tab:>-,trail:.,precedes:<,extends:>,eol:$

"42header ======================================================================
let g:user42 = 'halvarez'
let g:mail42 = 'halvarez@student.42.fr'

"remapping =====================================================================
nnoremap <C-up> :resize +2<cr>
nnoremap <C-down> :resize -2<cr>
nnoremap <C-right> :vertical resize +2<cr>
nnoremap <C-left> :vertical resize -2<cr>
inoremap <Esc> <Esc>:w<CR>

"autoclosing ===================================================================
inoremap ( ()<Left>
inoremap [ []<Left>
inoremap { {}<Left>
inoremap " ""<Left>
inoremap ' ''<Left>
inoremap /* /**/<Left><Left>
