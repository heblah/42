/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:20:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/29 13:52:31 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = -1;
	while (length > ++i)
		f(tab[i]);
}
/*
void	ft_putchar(int c)
{
	c = c + '0';
	write(1, &c, 1);
}

int	main(void)
{
	int	tab[] = {0, 1, 2, 3, 4, 5, 6};

	ft_foreach(tab, 7, &ft_putchar);
}
*/
