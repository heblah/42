/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:48:24 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/20 18:07:54 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"prototypes.h"

/*cree le tableau de 6 * 6*/
int	**init_tab(void)
{
	int	**tab;
	int	i;

	i = -1;
	tab = (int **)malloc((SIZE + 2) * sizeof(int *));
	while (++i < (SIZE + 2))
		tab[i] = (int *)malloc((SIZE + 2) * sizeof(int));
	return (tab);
}

/*convertit la str_input en tableau d'int sans espace*/
int	*input_to_int(char *str)
{
	int	*tab_int;
	int	i;
	int	j;

	i = -1;
	j = -1;
	tab_int = (int *)malloc((SIZE * 4) * sizeof(int));
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= SIZE + '0')
			tab_int[++j] = str[i] - '0';
	}
	return (tab_int);
}

/*ecrit les contraintes dans un tableau de 6*6 et free le tableau
d'int precedent*/
int	**fill_tab(char *str)
{
	int	i;
	int	*tab_int;
	int	**tab;

	tab_int = input_to_int(str);
	if (!is_valid_constraint(tab_int))
	{
		free(tab_int);
		return (NULL);
	}
	tab = init_tab();
	i = 0;
	while (i < SIZE)
	{
			tab[0][i + 1] = tab_int[i];
			tab[SIZE + 1][i + 1] = tab_int[i + SIZE];
			tab[i + 1][0] = tab_int[i + 2 * SIZE];
			tab[i + 1][SIZE + 1] = tab_int[i + 3 * SIZE];
			i++;
	}
	tab = fill_with_zero(tab);
	free(tab_int);
	return (tab);
}

int	**fill_with_zero(int **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	tab[0][0] = 0;
	tab[0][SIZE + 1] = 0;
	tab[SIZE + 1][0] = 0;
	tab[SIZE + 1][SIZE + 1] = 0;
	while (++i <= SIZE)
	{
		while (++j <= SIZE)
			tab[i][j] = 0;
	}
	return (tab);
}
