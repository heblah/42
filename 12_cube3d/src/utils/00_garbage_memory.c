/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_garbage_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:25:37 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/10 13:17:57 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"
#define ERROR "Error alllocating memory, exiting cub3D.\n"

void	*free_label(t_garbage *garbage, t_label label)
{
	while (garbage)
	{
		if (garbage->label == label)
		{
			free(garbage->address);
			garbage->address = NULL;
		}
		garbage = garbage->next;
	}
	return (NULL);
}

void	*free_adr(t_garbage *garbage, void *adr)
{
	while (garbage)
	{
		if (garbage->address == adr)
		{
			free(garbage->address);
			garbage->address = NULL;
		}
		garbage = garbage->next;
	}
	return (NULL);
}

void	*purge_garbage(t_garbage *garbage)
{
	t_garbage	*tmp;

	tmp = garbage;
	while (garbage->next)
	{
		tmp = garbage;
		free(tmp->address);
		garbage = garbage->next;
		free(tmp);
	}
	free(garbage->address);
	free(garbage);
	return (NULL);
}

void	*add_garbage(t_data *data, size_t size, void *adr, t_label label)
{
	t_garbage	*new;

	new = malloc(sizeof(t_garbage));
	if (!new)
		return (ft_putstr_fd(ERROR, 2), memg(PURGE, 0, NULL, 0), exit(1), NULL);
	if (adr)
		new->address = adr;
	else
		new->address = malloc(size);
	if (!new->address)
		return (ft_putstr_fd(ERROR, 2), memg(PURGE, 0, NULL, 0), exit(1), NULL);
	new->label = label;
	if (data->garbage)
	{
		new->next = data->garbage;
		data->garbage = new;
	}
	else if (data->garbage == NULL)
	{
		new->next = NULL;
		data->garbage = new;
	}
	return (new->address);
}

//memg(MALLOC, sizeof(TYPE), NULL, NOTHING);
void	*memg(t_memt type, size_t size, void *adr, t_label label)
{
	t_data		*data;
	t_garbage	*garb;

	data = getdata();
	garb = data->garbage;
	if (type == MALLOC)
		return (add_garbage(data, size, adr, label));
	else if (type == PURGE && garb)
		return (purge_garbage(garb));
	else if (type == LABEL && garb)
		return (free_label(garb, label));
	else if (type == FREE && garb)
		return (free_adr(garb, adr));
	return (NULL);
}
