/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binnbr_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/05 18:01:18 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int	n;

	n = 0;
	n = 1 << 1 | 1 << 3 | 1 << 31;
	printf("n = %d\n", n);
	printf("unsigned n = %u\n", n);
	return (0);
}
