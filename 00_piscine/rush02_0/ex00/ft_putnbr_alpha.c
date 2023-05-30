/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 10:34:51 by aquincho          #+#    #+#             */
/*   Updated: 2022/03/27 21:59:19 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*cheche valeur tofind dans la liste. stype = 0 : n_num, stype = 1: n_size*/
int	ft_find_in_list(char *tofind, int tofindsize, t_dico *dico_list, int stype)
{
	t_dico	*tmp;

	tmp = dico_list;
	while (tmp->next_elem != NULL)
	{
		if ((stype == 0 && ft_strcmp(tmp->n_num, tofind) == 0)
			|| (stype == 1 && tmp->n_size == tofindsize))
		{
			ft_putstr(tmp->n_alpha);
			return (0);
		}
		tmp = tmp->next_elem;
	}
	return (-1);
}

int	ft_putnber_three_digits(char *nbr, t_dico *dico_list, int fin)
{
	int		nbr_len;
	char	tmp[4];

	nbr_len = ft_strlen(nbr);
	if (nbr_len > 3 || nbr_len < 1)
		return (-1);
	if (nbr_len == 3)
	{
		if (nbr[0] != '0')
		{
			tmp[0] = nbr[0];
			tmp[1] = '\0';
			ft_find_in_list(tmp, 0, dico_list, 0);
			ft_putstr(" ");
			if (nbr_len > 2)
				ft_find_in_list("", nbr_len, dico_list, 1);
			ft_putstr(" ");
		}
		nbr += 1;
		nbr_len = ft_strlen(nbr);
	}
	if (nbr_len == 2)
	{
		if (nbr[0] > '2')
		{
			tmp[0] = nbr[0];
			tmp[1] = '0';
			tmp[2] = '\0';
			ft_find_in_list(tmp, 0, dico_list, 0);
			ft_putstr(" ");
		}
		if (nbr[0] != '1')
		{
			nbr += 1;
			nbr_len = ft_strlen(nbr);
		}
	}
	if (nbr[0] != '0' )
		ft_find_in_list(nbr, 0, dico_list, 0);
	if (!fin)
		ft_putstr(" ");
	return (0);
}

int	ft_putnbr_alpha(char *nbr, t_dico *dico_list)
{
	int		nbr_size;
	int		nbr_modulo;
	char	tmp[4];
	int		i;

	i = 0;
	nbr_size = ft_strlen(nbr);
	if (nbr_size == 1 && nbr[i] == '0')
		ft_find_in_list(nbr, 0, dico_list, 1);
	while (nbr_size > 3)
	{
		i = 0;
		while (nbr[0] == '0' && nbr[1] == '0' && nbr[2] == '0')
			nbr += 3;
		nbr_modulo = nbr_size % 3;
		if (nbr_modulo == 0)
			nbr_modulo = 3;
		while (nbr_modulo > 0)
		{
			tmp[i] = nbr[0];
			nbr += 1;
			i++;
			nbr_modulo--;
		}
		tmp[i] = '\0';
		nbr_size = ft_strlen(nbr);
		ft_putnber_three_digits(tmp, dico_list, 0);
		if (nbr_size > 1)
		{
			ft_find_in_list("", nbr_size + 1, dico_list, 1);
			ft_putstr(" ");
		}
		i = 0;
	}
	ft_putnber_three_digits(nbr, dico_list, 1);
	return (0);
}
