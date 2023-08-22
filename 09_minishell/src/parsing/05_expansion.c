/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:18:23 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/14 16:09:23 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

void	expanser(t_data *data, t_lst *cmd_lst)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (cmd_lst && cmd_lst->cmd && cmd_lst->cmd[i])
	{
		j = 0;
		if (ft_strncmp(cmd_lst->cmd[i], "<", ft_strlen("<") + 1) == 0)
			expand_infile(cmd_lst, i);
		else if (cmd_lst->cmd[i][j] && cmd_lst->cmd[i][j] == '>')
		{
			if (cmd_lst->cmd[i][j + 1] && cmd_lst->cmd[i][j + 1] == '>')
			{
				expand_outfile(cmd_lst, i, O_APPEND);
				continue ;
			}
			expand_outfile(cmd_lst, i, O_TRUNC);
		}
		i++;
	}
	checkfor_heredoc(cmd_lst);
	if (cmd_lst && cmd_lst->next != NULL)
		expanser(data, cmd_lst->next);
}

char	*joinvar(char **var)
{
	char	*str;
	size_t	i;

	i = 0;
	str = NULL;
	while (var && *(var + i))
	{
		str = ft_strjoin(str, *(var + i));
		if (str == NULL)
			return (NULL);
		memg(MALLOC, 0, str, PARSE);
		i++;
	}
	return (str);
}

void	expand_infile(t_lst *cmd_lst, size_t i)
{
	int		fd_in;

	fd_in = -1;
	if (cmd_lst->cmd[i] && cmd_lst->cmd[i + 1])
	{
		fd_in = open(cmd_lst->cmd[i + 1], O_RDONLY);
		if (fd_in == -1)
			perror("expansion");
		else
			cmd_lst->fd_in = fd_in;
		while (cmd_lst->cmd[i] && cmd_lst->cmd[i + 2])
		{
			cmd_lst->cmd[i] = cmd_lst->cmd[i + 2];
			i++;
		}
		cmd_lst->cmd[i] = NULL;
	}
	else
		ft_putstr_fd("minishell: parse error", 2);
}

void	expand_outfile(t_lst *cmd_lst, size_t i, int type)
{
	int		fd_out;

	if (cmd_lst->cmd[i] && cmd_lst->cmd[i + 1])
	{
		fd_out = open(cmd_lst->cmd[i + 1], O_WRONLY | type, 0644);
		if (fd_out == -1)
		{
			fd_out = open(cmd_lst->cmd[i + 1], O_WRONLY | O_CREAT, 0644);
			if (fd_out == -1)
				perror("expansion");
		}
		if (fd_out != -1)
			cmd_lst->fd_out = fd_out;
		while (cmd_lst->cmd[i] && cmd_lst->cmd[i + 2])
		{
			cmd_lst->cmd[i] = cmd_lst->cmd[i + 2];
			i++;
		}
		cmd_lst->cmd[i] = NULL;
	}
	else
		ft_putstr_fd("minishell: parse error", 2);
}
