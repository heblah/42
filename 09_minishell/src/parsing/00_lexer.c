/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:42:39 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/07 17:58:24 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

static t_lexer	*create_lexingtab(char *input)
{
	t_lexer		*lexer;
	const int	row = 3;
	int			i;

	i = 0;
	lexer = memg(MALLOC, 1 * sizeof(t_lexer), NULL, LEXER);
	if (lexer == NULL)
		return (perror("lexer"), NULL);
	lexer->tab = memg(MALLOC, row * sizeof(int *), NULL, LEXER);
	if (lexer->tab == NULL)
		return (memg(FREE, 0, lexer, LEXER), perror("lexer"), NULL);
	while (i < row)
	{
		*(lexer->tab + i) = memg(MALLOC,
				(ft_strlen(input) + 1) * sizeof(int), NULL, LEXER);
		if (*(lexer->tab + i) == NULL)
		{
			while (--i >= 0)
				memg(FREE, 0, *(lexer->tab + i), LEXER);
			memg(FREE, 0, lexer->tab, LEXER);
			return (perror("lexer"), NULL);
		}
		i++;
	}
	return (lexer);
}

static void	get_chartype(t_lexer *lexer)
{
	size_t			i;
	const t_token	token_tab[] = {
	['\0'] = C_NULL,
	['|'] = C_PIPE,
	['&'] = C_AMPERSAND,
	['<'] = C_INF,
	['>'] = C_SUP,
	['$'] = C_DOLLAR,
	['\''] = C_SQUOTE,
	['\"'] = C_DQUOTE,
	[' '] = C_SPACE,
	['*'] = C_WILDCARD,
	['~'] = C_WORD};

	i = 0;
	while (i < lexer->len)
	{
		if (token_tab[*(*(lexer->tab + INPUT) + i)] != 0)
			lexer->tab[TOKEN][i] = token_tab[lexer->tab[INPUT][i]];
		else if (i > 0 && lexer->tab[TOKEN][i - 1] == C_DOLLAR)
			lexer->tab[TOKEN][i] = C_DOLLAR;
		i++;
	}
	lexer->tab[TOKEN][i] = C_NULL;
}

static void	init_lexer(t_lexer *lexer, char *input, size_t len)
{
	size_t	i;

	i = 0;
	lexer->len = len;
	while (i < lexer->len)
	{
		lexer->tab[INPUT][i] = *(input + i);
		lexer->tab[TOKEN][i] = C_WORD;
		lexer->tab[STATE][i] = S_GENERAL;
		i++;
	}
	lexer->tab[INPUT][i] = C_NULL;
}

static t_bool	get_state(t_lexer *lexer, int inquote)
{
	size_t	i;
	t_bool	inquotecpy;

	i = 0;
	inquotecpy = inquote;
	while (i < lexer->len)
	{
		write_state(lexer, &i, &inquotecpy);
		i++;
	}
	return (inquotecpy);
}

//printf("cmd_lst = %p\n", data->cmd_lst);
//printf("parser = %p\n", data->parser);
int	lexer(t_data *data, char *input)
{
	if (*input)
	{
		memg(LABEL, 0, NULL, LEXER);
		memg(LABEL, 0, NULL, PARSE);
		memg(LABEL, 0, NULL, EXECV);
		data->cmd_lst = NULL;
		arglen(data->lexer, true);
		data->lexer = create_lexingtab(input);
		init_lexer(data->lexer, input, ft_strlen(input));
		get_chartype(data->lexer);
		if (get_state(data->lexer, false) == true)
			return (ft_putstr_fd("Error : unclosed quote.\n", 2), -1);
	}
	return (0);
}
