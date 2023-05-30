/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/07 18:37:57 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int			a	= 42;
	const int * const p	= &a;

	printf("a = %d\n", a);
	*p += 1;
	printf("a = %d\n", a);
	return (0);
}
