/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:52:09 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/19 17:37:33 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

char	*prompt(void)
{
	char	*cmd;

	while (1)
	{
		cmd = readline("minihsell > ");
		if (check_cmd(cmd) != 0)
			add_history(cmd);
	}
	return (cmd);
}

int	check_cmd(const char *cmd)
{
	size_t	blank;
	size_t	i;

	i = 0;
	blank = 0;
	while (*(cmd + i + blank))
	{
		if (*(cmd + i + blank) == ' ' || *(cmd + i + blank) == '\t')
			blank++;
		else
			i++;
	}
	if (ft_strlen(cmd) == blank)
		return (0);
	else
		return (i);
}
