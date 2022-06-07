/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembly.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:26:27 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/19 15:40:21 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main()
{
	__asm__(	"push	rbp;"
	1139:		55                      push   rbp
    113a:		48 89 e5                mov    rbp,rsp
    113d:		48 89 7d e8             mov    QWORD PTR [rbp-0x18],rdi
    1141:		48 8b 45 e8             mov    rax,QWORD PTR [rbp-0x18]
    1145:		48 89 45 f8             mov    QWORD PTR [rbp-0x8],rax
    1149:		48 8b 45 f8             mov    rax,QWORD PTR [rbp-0x8]
    114d:		8b 00                   mov    eax,DWORD PTR [rax]
    114f:		35 40 20 5b 7f          xor    eax,0x7f5b2040
    1154:		89 45 f0                mov    DWORD PTR [rbp-0x10],eax
    1157:		48 8b 45 f8             mov    rax,QWORD PTR [rbp-0x8]
    115b:		48 83 c0 04             add    rax,0x4
    115f:		8b 00                   mov    eax,DWORD PTR [rax]
    1161:		35 53 23 59 76          xor    eax,0x76592353
    1166:		89 45 f4                mov    DWORD PTR [rbp-0xc],eax
    1169:		81 7d f0 37 13 37 13    cmp    DWORD PTR [rbp-0x10],0x13371337
    1170:       75 10                   jne    1182 <check_secret+0x49>
    1172:		81 7d f4 37 13 37 13    cmp    DWORD PTR [rbp-0xc],0x13371337
    1179:       75 07       		     jne    1182 <check_secret+0x49>
    117b:       b8 01 00 00 00          mov    eax,0x1
    1180:		eb 05                   jmp    1187 <check_secret+0x4e>
    1182:		b8 00 00 00 00          mov    eax,0x0
    1187:		5d                      pop    rbp
    1188:		c3                      ret

	);
	return (0);
}
