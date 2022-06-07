/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:26:27 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/19 16:13:12 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main()
{
"push   %rbp"
mov    %rbp,rsp
mov    QWORD PTR [rbp-0x18],rdi
mov    rax,QWORD PTR [rbp-0x18]
mov    QWORD PTR [rbp-0x8],rax
mov    rax,QWORD PTR [rbp-0x8]
mov    eax,DWORD PTR [rax]
xor    eax,0x7f5b2040
mov    DWORD PTR [rbp-0x10],eax
mov    rax,QWORD PTR [rbp-0x8]
add    rax,0x4
mov    eax,DWORD PTR [rax]
xor    eax,0x76592353
mov    DWORD PTR [rbp-0xc],eax
cmp    DWORD PTR [rbp-0x10],0x13371337
jne    1182 <check_secret+0x49>
cmp    DWORD PTR [rbp-0xc],0x13371337
jne    1182 <check_secret+0x49>
mov    eax,0x1
jmp    1187 <check_secret+0x4e>
mov    eax,0x0
pop    rbp
ret
	);
	return (0);
}
