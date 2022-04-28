/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:52:11 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/12 14:59:04 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i <= size - 1)
	{
		j = i + 1;
		while (j <= size)
		{
			if (*(tab + i) > *(tab + j))
				ft_swap(&tab[i], &tab[j]);
		j++;
		}
	i++;
	}
}

/*

#include<unistd.h>
#include<stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int	main(int argc, char **argv)
{
	int tab[] = {1, 99, 2, 65, -1, -65, 12};
	int	i;

	i = -1;
	ft_sort_int_tab(tab, 7);
	while (++i <= 7)
		printf("tab[%d] = %d\n", i, tab[i]);
}
*/
