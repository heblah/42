/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:35:16 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/27 21:58:36 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	int		status;
	char	dico_str[BUF_SIZE];

	if (argc == 2 || argc == 3)
	{
		status = ft_oandr("numbers.dict", dico_str);
		if (status < 0 || !ft_is_num(argv[argc - 1]))
		{
			ft_printerrors(-5);
			return (0);
		}
		if (argc == 2)
			ft_num_to_alph(dico_str, argv[argc - 1]);
		else
			ft_num_to_alph(argv[1], argv[argc - 1]);
	}
	else
		ft_printerrors(-5);
	return (0);
}

void	ft_num_to_alph(char *dico_str, char *arg)
{
	t_dico	*dico;

	dico = malloc(sizeof(t_dico));
	dico = ft_create_list(dico_str);
	ft_putnbr_alpha(arg, dico);
}
