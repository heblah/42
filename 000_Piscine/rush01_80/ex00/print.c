/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:39:49 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/20 10:00:29 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include"prototypes.h"

void	ft_print_error(void)
{
	write(1, "Error\n", 6);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_printtab(int **tab, int row, int column, int end)
{
	int	bkp;

	bkp = column;
	while (row <= end)
	{
		column = bkp;
		while (column <= end)
		{
			ft_putchar(tab[row][column] + '0');
			if (column == end)
				ft_putchar('\n');
			else
				ft_putchar(' ');
			column++;
		}
		row++;
	}
}
