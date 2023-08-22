/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:35:29 by halvarez          #+#    #+#             */
/*   Updated: 2022/11/12 18:04:24 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

t_bool	write_state(t_lexer *lexer, size_t *i, t_bool *inquote)
{
	if (lexer->tab[TOKEN][*i] == C_SQUOTE && *inquote == false)
		write_inquote(lexer, i, C_SQUOTE, inquote);
	else if (lexer->tab[TOKEN][*i] == C_DQUOTE && *inquote == false)
		write_inquote(lexer, i, C_DQUOTE, inquote);
	else if (lexer->tab[TOKEN][*i] == C_PIPE && *inquote == false)
		lexer->tab[STATE][*i] = S_PIPE;
	else if (lexer->tab[TOKEN][*i] == C_SPACE && *inquote == false)
		lexer->tab[STATE][*i] = S_SEP;
	else if (lexer->tab[TOKEN][*i] == C_INF && *inquote == false)
		lexer->tab[STATE][*i] = S_INF;
	else if (lexer->tab[TOKEN][*i] == C_SUP && *inquote == false)
		lexer->tab[STATE][*i] = S_SUP;
	else if (lexer->tab[TOKEN][*i] == C_DOLLAR && *inquote == false)
		lexer->tab[STATE][*i] = S_VAR;
	return (*inquote);
}

void	write_inquote(t_lexer *lexer, size_t *i, t_token token, t_bool *inquote)
{
	lexer->tab[STATE][*i] = S_SEP;
	*inquote = true;
	while (++*i < lexer->len && lexer->tab[TOKEN][*i] != token)
	{
		if (token == C_SQUOTE)
		{
			lexer->tab[TOKEN][*i] = C_WORD;
			lexer->tab[STATE][*i] = S_SINQUOTE;
		}
		else if (token == C_DQUOTE)
		{
			lexer->tab[STATE][*i] = S_DINQUOTE;
			if (lexer->tab[TOKEN][*i] == C_DOLLAR)
				lexer->tab[STATE][*i] = S_VAR;
			else if (lexer->tab[TOKEN][*i] != C_DOLLAR)
				lexer->tab[TOKEN][*i] = C_WORD;
		}
	}
	if (*i < lexer->len && lexer->tab[TOKEN][*i] == token)
		*inquote = false;
	lexer->tab[STATE][*i] = S_SEP;
}
