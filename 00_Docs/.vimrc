" **************************************************************************** "
"                                                                              "
"                                                         :::      ::::::::    "
"    .vimrc                                             :+:      :+:    :+:    "
"                                                     +:+ +:+         +:+      "
"    By: hans </var/spool/mail/hans>                +#+  +:+       +#+         "
"                                                 +#+#+#+#+#+   +#+            "
"    Created: 2022/06/01 00:09:52 by hans              #+#    #+#              "
"    Updated: 2022/06/01 08:45:31 by hans             ###   ########.fr        "
"                                                                              "
" **************************************************************************** "

"vim config ====================================================================
:syntax on
set	number
set	tabstop=4
set	shiftwidth=4
set	showcmd
set	smartindent
set	autoindent
set	listchars=tab:>-,trail:.,precedes:<,extends:>,eol:$

"remapping =====================================================================
nnoremap <C-up> :resize +2<cr>
nnoremap <C-down> :resize -2<cr>
nnoremap <C-right> :vertical resize +2<cr>
nnoremap <C-left> :vertical resize -2<cr>

"autoclosing ===================================================================
inoremap ( ()<Left>
inoremap [ []<Left>
inoremap " ""<Left>
inoremap { {<Return>}<Up><Return>
inoremap <Esc> <Esc>:w<CR>
