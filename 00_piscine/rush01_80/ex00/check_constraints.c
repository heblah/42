/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_constraints.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:55:53 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/20 15:04:17 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"prototypes.h"

int	is_valid_input(char *str)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		if (i % 2 == 0 && (str[i] >= '0' && str[i] <= SIZE + '0'))
			cnt++;
		else if (i % 2 == 0 && (str[i] < '0' || str[i] > SIZE + '0'))
			return (0);
		else if (i % 2 == 1 && str[i] != ' ')
			return (0);
		i++;
	}
	if (cnt / 4 != SIZE)
		return (0);
	return (1);
}

int	is_valid_constraint(int *tab_int)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (tab_int[i] + tab_int[i + SIZE] > SIZE + 1)
			return (0);
		else if (tab_int[i + 2 * SIZE] + tab_int[i + 3 * SIZE] > SIZE + 1)
			return (0);
		i++;
	}
	return (1);
}
