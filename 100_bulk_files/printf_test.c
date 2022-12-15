/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:25:58 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/14 15:54:16 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define CMD(x) "/bin/"(#x)
#define HLP(x) CMD(x)
#define EXC(x) HLP(x)

int	main(void)
{
	printf(EXC(bash));
	printf("\n");
	return (0);
}
