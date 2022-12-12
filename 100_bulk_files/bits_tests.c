/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:02:17 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/09 12:40:28 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char	a, b, c;

	a = 0;
	a = 1 << 2;
	printf("a\t=\t%d\n", a);
	a = a << 1;
	printf("a\t=\t%d\n", a << 0);
	a = 255;
	a &= ~a;
	printf("a\t=\t%d\n", a);
	return (0);
}
