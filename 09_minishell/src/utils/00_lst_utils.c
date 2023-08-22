/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:27:20 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/05 15:56:04 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

/* new(becomes first) <-> elem1 <-> elem2 <-> ... */
/* first <-> elem1 <-> ... <-> elemX <-> new */
void	*ft_addback(t_lst **first, char **new_cmd, t_label label)
{
	t_lst	*new;
	t_lst	*tmp;

	new = memg(MALLOC, 1 * sizeof(t_lst), NULL, label);
	if (new == NULL)
		return (perror("Addback cmds"), memg(LABEL, 0, NULL, label), NULL);
	new->cmd = new_cmd;
	new->fd_in = STDIN_FILENO;
	new->fd_out = STDOUT_FILENO;
	new->exec = true;
	new->next = NULL;
	if (first && *first)
	{
		tmp = *first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else if (first && *first == NULL)
		*first = new;
	return (*first);
}

void	ft_freelst(t_lst **first)
{
	t_lst	*tmp;

	if (first && *first)
	{
		while (*first != NULL)
		{
			tmp = *first;
			*first = (*first)->next;
			free(tmp);
		}
		*first = NULL;
	}
}
