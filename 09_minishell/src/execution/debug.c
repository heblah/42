/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:03:58 by halvarez          #+#    #+#             */
/*   Updated: 2022/11/21 10:45:08 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

void	print_lexer(t_lexer *lexer)
{
	size_t	i;

	i = -1;
	printf("\n");
	printf("[INPUT][%ls]\n", lexer->tab[INPUT]);
	while (++i < lexer->len)
		printf("[%ld] \t[C:][%c] \t[T:][%d] \t[S:][%d]\n", i, lexer->tab[INPUT][i],
			lexer->tab[TOKEN][i], lexer->tab[STATE][i]);
	printf("\n");
}

/* Fonction a commenter pour le push final */
/*
void	debug_func(t_data *data)
{
	size_t			cmd;

	data->nb_cmds = count_cmd(data->lexer);
	cmd = count_cmd(data->lexer);
	data->parser = count_args(data->lexer, data->parser, cmd);
}
*/

void	print_execv(t_lst *cmd_lst)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (cmd_lst)
	{
		printf("cmd[%ld] :\n", i);
		j = 0;
		while (*(cmd_lst->cmd + j) != NULL)
		{
			printf("  arg[%ld] =%s\n", j, *(cmd_lst->cmd + j));
			j++;
		}
		printf("\n");
		cmd_lst = cmd_lst->next;
		i++;
	}
}
