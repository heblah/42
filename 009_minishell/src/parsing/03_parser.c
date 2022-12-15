/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:38:31 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/07 09:44:59 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

/* parser[x] : nbr of args for the cmd x */
size_t	*count_args(t_lexer *lexer, size_t *parser, size_t nb_cmd)
{
	size_t	i;
	size_t	cmd;
	int		state;

	i = 0;
	cmd = 0;
	if (init_parser(&parser, nb_cmd) == -1)
		return (NULL);
	while (i < lexer->len)
	{
		while (i < lexer->len && (lexer->tab[STATE][i] == S_SEP
			|| lexer->tab[STATE][i] == S_PIPE))
		{
			if (lexer->tab[STATE][i] == S_PIPE)
				cmd++;
			i++;
		}
		state = lexer->tab[STATE][i];
		if (i < lexer->len && lexer->tab[STATE][i] != S_PIPE)
			*(parser + cmd) += 1;
		while (i < lexer->len && lexer->tab[STATE][i] == state)
			i++;
	}
	return (parser);
}

int	init_parser(size_t **parser, size_t nb_cmd)
{
	size_t	i;

	i = 0;
	*parser = memg(MALLOC, nb_cmd * sizeof(size_t), NULL, PARSE);
	if (*parser == NULL)
		return (perror("Parser"), -1);
	while (i < nb_cmd)
		*(*parser + i++) = 0;
	return (0);
}

size_t	arglen(t_lexer *lexer, t_bool reset)
{
	static size_t	i = 0;
	size_t			len;
	int				state;

	len = 0;
	if (reset == true)
		i = 0;
	else
	{
		while ((i + len) < lexer->len && (lexer->tab[STATE][i] == S_SEP
			|| lexer->tab[STATE][i] == S_PIPE))
			i++;
		state = lexer->tab[STATE][i];
		while ((i + len) < lexer->len
			&& lexer->tab[STATE][i + len] == state)
			len++;
		i += len;
	}
	return (len);
}

t_lst	*alloc_exec(t_data *data, size_t cmd_nbr)
{
	char	**cmd;
	size_t	len_arg;
	size_t	j;

	cmd = memg(MALLOC,
			(data->parser[cmd_nbr] + 1) * sizeof(char *), NULL, EXECV);
	if (cmd == NULL)
		return (perror("Alloc_exec"), NULL);
	*(cmd + data->parser[cmd_nbr]) = NULL;
	j = 0;
	while (j < data->parser[cmd_nbr])
	{
		len_arg = arglen(data->lexer, false);
		cmd[j] = memg(MALLOC, (len_arg + 1) * sizeof(char), NULL, EXECV);
		if (cmd[j] == NULL)
			return (perror("Alloc exec"), memg(LABEL, 0, NULL, EXECV));
		ft_memset(cmd[j], '\0', len_arg + 1);
		j++;
	}
	if (ft_addback(&data->cmd_lst, cmd, EXECV) == NULL)
		return (NULL);
	return (data->cmd_lst);
}

char	**cmdcpy(t_lexer *lexer, char **cmd, size_t cmd_nbr)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		state;

	i = 0;
	j = goto_cmd(lexer, cmd_nbr);
	while (*(cmd + i) != NULL)
	{
		while (j < lexer->len && lexer->tab[STATE][j] == S_SEP)
			j++;
		k = -1;
		state = lexer->tab[STATE][j];
		while (j + ++k < lexer->len && lexer->tab[STATE][j + k] == state
			&& lexer->tab[STATE][j + k] != S_SEP
			&& lexer->tab[STATE][j + k] != S_PIPE)
			*(*(cmd + i) + k) = lexer->tab[INPUT][j + k];
		*(*(cmd + i++) + k) = '\0';
		if (cmd_checker(cmd, state, i - 1) == NULL)
			return (NULL);
		j += k;
	}
	return (cmd);
}
