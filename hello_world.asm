# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    hello_world.asm                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 15:14:13 by halvarez          #+#    #+#              #
#    Updated: 2022/10/07 15:20:37 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.data
hello:
	.string db "Hello world !", 10
	.len 	equ $ - hello.string

section	.text
	global _start
	global _main

_start:
	call _main
	ret

_main:
	mov	rax,	1
	mov	rdi,	1
	mov	rsi,	hello.string
	mov	rdx,	hello.len
	syscall
	mov	rax,	60
	mov	rdi,	0
	syscall
