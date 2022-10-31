/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:27:20 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/31 15:59:18 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

/* new(becomes first) <-> elem1 <-> elem2 <-> ... */
void	ft_addfront(t_lst **first, char **new_cmd)
{
	t_lst	*new;

	new = malloc(1 * sizeof(t_lst));
	if (!new)
		return (perror("Addfront cmds"), NULL);
	new->cmds = new_cmd;
	new->back = NULL;
	new->next = NULL;
	if (first && *first)
	{
		new->next = *first;
		*first = new;
	}
	else if (first && *first == NULL)
		*first = new;
}

/* first <-> elem1 <-> ... <-> elemX <-> new */
void	ft_addback(t_lst **first, char **new_cmd)
{
	t_lst	*new;
	t_lst	*tmp;

	new = malloc(1 * sizeof(t_lst));
	if (new == NULL)
		return (perror("Addback cmds"), NULL);
	new->cmds = new_cmd;
	new->back = NULL;
	new->next = NULL;
	if (first && *first)
	{
		tmp = *first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->back = tmp;
	}
	else if (first && *first == NULL)
		*first = new;
}

void	ft_freelst(t_lst **first)
{
	t_lst	*tmp;
	t_lst	*tmp_first;

	if (first && *first && (*first)->back == NULL)
	{
		while (*first != NULL)
		{
			tmp = *first;
			*first = (*first)->next;
			free(tmp);
		}
	}
	else if (first && *first && (*first)->back != NULL)
	{
		tmp_first = (*first)->back;
		while (tmp_first)
		{
			tmp = tmp_first;
			tmp_first = tmp_firsr->back;
			free(tmp);
		}
		(*first)->back = NULL;
		ft_freelst(first);
	}
}
