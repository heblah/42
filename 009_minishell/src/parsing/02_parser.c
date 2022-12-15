/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:21:36 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/07 09:41:44 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

/* cmd_number--:33 if first cmd == 1 */
size_t	lencmd(t_lexer *lexer, size_t cmd_number)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < lexer->len && cmd_number > 0 && lexer->tab[STATE][i] != S_PIPE)
	{
		i++;
		if (lexer->tab[STATE][i] == S_PIPE)
		{
			cmd_number--;
			i++;
		}
	}
	while (i + j < lexer->len && lexer->tab[STATE][i + j] != S_PIPE)
		j++;
	return (j);
}

static size_t	count_cmd(t_lexer *lexer)
{
	size_t	count;
	size_t	i;

	count = 1;
	i = 0;
	while (i < lexer->len)
	{
		if (lexer->tab[STATE][i] == S_PIPE)
			count++;
		i++;
	}
	return (count);
}

size_t	goto_cmd(t_lexer *lexer, size_t cmd_nbr)
{
	size_t	i;

	i = 0;
	while (i < lexer->len && cmd_nbr > 0 && lexer->tab[STATE][i] != S_PIPE)
	{
		i++;
		if (i < lexer->len && lexer->tab[STATE][i] == S_PIPE)
		{
			cmd_nbr--;
			i++;
		}
	}
	return (i);
}

void	*parser(t_data *data)
{
	t_lst	*tmp_lst;
	size_t	nb_cmd;
	size_t	i;

	nb_cmd = count_cmd(data->lexer);
	tmp_lst = NULL;
	i = 0;
	while (i < nb_cmd)
	{
		data->parser = count_args(data->lexer, data->parser, nb_cmd);
		if (alloc_exec(data, i) == NULL)
			return (NULL);
		if (i == 0)
			tmp_lst = data->cmd_lst;
		else
			tmp_lst = tmp_lst->next;
		cmdcpy(data->lexer, tmp_lst->cmd, i);
		i++;
	}
	return (data->cmd_lst);
}
