/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:52:09 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/14 16:44:39 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

static int	check_cmd(const char *cmd)
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

static t_bool	pipe_err(char *cmd)
{
	size_t	i;
	size_t	len;
	t_data	*data;

	i = 0;
	len = ft_strlen(cmd);
	data = get_data();
	if (cmd && cmd[i] == '|')
		return (data->status = 1,
			ft_putstr_fd("minishell: parse error near `|'\n", 2), true);
	while (i <= len && i + 1 <= len)
	{
		if (cmd[i] == '|' && cmd[i + 1] == '|')
			return (data->status = 1,
				ft_putstr_fd("minishell: parse error near `|'\n", 2), true);
		if (cmd[i] == '|' && cmd[i + 1] == '\0')
			return (data->status = 1, ft_putstr_fd("minishell: "
					"error: no command after the pipe `|'.\n", 2), true);
		i++;
	}
	return (false);
}

char	*prompt(t_data *data)
{
	char	*cmd;

	cmd = NULL;
	while (data->run)
	{
		start_signal();
		cmd = readline("minishell > ");
		memg(MALLOC, 0, cmd, OTHER);
		if (cmd != NULL && check_cmd(cmd) != 0)
			add_history(cmd);
		if (cmd == NULL)
		{
			ft_putstr_fd("exit\n", 1);
			break ;
		}
		if (cmd != NULL && check_cmd(cmd) != 0 && pipe_err(cmd) == false)
			exec_cmd(data, cmd);
		if (cmd)
			memg(FREE, 0, cmd, OTHER);
	}
	rl_clear_history();
	memg(PURGE, 0, NULL, 0);
	exit(data->status);
	return (NULL);
}
