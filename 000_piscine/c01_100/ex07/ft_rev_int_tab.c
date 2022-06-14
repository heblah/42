/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:49:39 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/12 13:58:57 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;

	i = 0;
	while (--size >= i)
	{
		tmp = tab[i];
		tab[i] = tab[size];
		tab[size] = tmp;
		i++;
	}	
}

/*

#include<unistd.h>
#include<stdio.h>

void	ft_rev_int_tab(int *tab, int size);

int	main(int argc, char **argv)
{
	//int	test[6];
	int	n;

	int test[] = {0, 1, 2, 3, 4, 5, 6};
	ft_rev_int_tab(test, 7);
	n = 0;
	while (n < 7)
	{
		printf("test[%d] = %d\n", n, test[n]);
		n++;
	}
	return (0);
}
*/
