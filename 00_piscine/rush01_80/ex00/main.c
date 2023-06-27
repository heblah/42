/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:46:54 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/20 21:22:14 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"prototypes.h"

int	main(int argc, char **argv)
{
	int	**tab;

	if (argc != 2)
		ft_print_error();
	else if (!is_valid_input(argv[1]))
		ft_print_error();
	else
	{
		tab = fill_tab(argv[1]);
		if (tab == NULL)
			ft_print_error();
		else
		{
			if (ft_resol(tab, 1, 1))
				ft_printtab(tab, 1, 1, SIZE);
			else
				ft_print_error();
		}
	}
	free(tab);
	return (0);
}
