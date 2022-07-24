/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:39:43 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/22 15:56:41 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	*test(void);

int main(void)
{
	int	*p;

	p = test();
	printf("%d\n", *p);
	return (0);
}

int	*test(void)
{
	int a;

	a = 9999;
	return (&a);
}
