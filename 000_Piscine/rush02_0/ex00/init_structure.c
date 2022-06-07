/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:42:42 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/27 19:58:25 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_write_next_num(char *dicostr, t_dico *elem, int i)
{
	int	j;
	int	k;

	if (i < 0)
		return (-1);
	while (!(dicostr[i] >= '0' && dicostr[i] <= '9'))
	{
		if (dicostr[i] == '\0')
			return (-1);
		i++;
	}
	j = i;
	k = 0;
	while (dicostr[j] >= '0' && dicostr[j] <= '9')
		j++;
	elem->n_num = malloc(sizeof(char) * (j - i + 1));
	elem->n_size = j - i;
	while (i < j)
	{
		elem->n_num[k] = dicostr[i];
		k++;
		i++;
	}
	elem->n_num[k] = '\0';
	return (i);
}

int	ft_write_next_alpha(char *dicostr, t_dico *elem, int i)
{
	int	j;
	int	k;

	if (i < 0)
		return (-1);
	while (!ft_is_printable(dicostr[i]) || dicostr[i] == ':')
	{
		if (dicostr[i] == '\0')
			return (-1);
		i++;
	}
	j = i;
	k = 0;
	while (ft_is_printable(dicostr[j]) && dicostr[j] != ':')
		j++;
	elem->n_alpha = malloc(sizeof(char) * (j - i + 1));
	while (i < j)
	{
		elem->n_alpha[k] = dicostr[i];
		k++;
		i++;
	}
	elem->n_alpha[k] = '\0';
	return (i);
}

int	ft_create_elem(char *dicostr, t_dico *dico_list, int index)
{
	t_dico	*new_elem;
	t_dico	*tmp;

	new_elem = malloc(sizeof(t_dico));
	if (!new_elem)
		return (-1);
	new_elem->next_elem = NULL;
	index = ft_write_next_num(dicostr, new_elem, index);
	index = ft_write_next_alpha(dicostr, new_elem, index);
	if (index < 0)
		free (new_elem);
	else
	{
		if (dico_list == NULL)
			dico_list = new_elem;
		else
		{
			tmp = 0;
			tmp = dico_list;
			while (tmp->next_elem != NULL)
				tmp = tmp->next_elem;
			tmp->next_elem = new_elem;
		}
	}
	return (index);
}

t_dico	*ft_create_list(char *dicostr)
{
	t_dico	*dico_list;
	int		index;

	dico_list = malloc(sizeof(t_dico));
	dico_list->n_num = "";
	dico_list->n_alpha = "";
	dico_list->n_size = 0;
	dico_list->next_elem = NULL;
	index = 0;
	while (index >= 0)
	{
		index = ft_create_elem(dicostr, dico_list, index);
	}
	return (dico_list);
}
