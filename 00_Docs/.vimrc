" **************************************************************************** "
"                                                                              "
"                                                         :::      ::::::::    "
"    .vimrc                                             :+:      :+:    :+:    "
"                                                     +:+ +:+         +:+      "
"    By: halvarez <marvin@42.fr>                    +#+  +:+       +#+         "
"                                                 +#+#+#+#+#+   +#+            "
"    Created: 2022/03/12 10:18:24 by halvarez          #+#    #+#              "
"    Updated: 2022/05/03 18:07:46 by halvarez         ###   ########.fr        "
"                                                                              "
" **************************************************************************** "


"theme vim
"let data_dir = has('nvim') ? stdpath('data') . '/site' : '~/.vim'
"if empty(glob(data_dir . '/autoload/plug.vim'))
"  silent execute '!curl -fLo '.data_dir.'/autoload/plug.vim --create-dirs  https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim'
"  autocmd VimEnter * PlugInstall --sync | source $MYVIMRC
"endif

"call plug#begin(expand('~/.vim/plugged'))
"Plug 'arcticicestudio/nord-vim'
"call plug#end()
"colorscheme nord


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
"set expandtab
"set list!
"set nosmartindent
"set noautoindent
