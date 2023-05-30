/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:32:49 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/12 13:16:54 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp;	

	tmp = *a / *b;
	*b = *a % *b;
	*a = tmp;
}

/*

#include<stdio.h>

int	main(int argc, char **argv)
{
	int	a;
	int	b;

	a = 100;
	b = 10;
	ft_ultimate_div_mod(&a, &b);
	printf("a = %d\nb = %d\n", a, b);
}
*/
