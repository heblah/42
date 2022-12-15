/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:45:05 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/14 16:40:12 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

static void	writeif_fd(int fd, char *inpt, t_bool is_writing)
{
	t_data	*data;
	t_lst	*buffer;

	data = get_data();
	buffer = data->buf;
	if (is_writing == true)
		ft_addback(&data->buf, (char **)inpt, EXECV);
	else if (is_writing == false)
	{
		while (buffer != NULL)
		{
			write(fd, (char *)buffer->cmd, ft_strlen((char *)buffer->cmd));
			write(fd, "\n", 1);
			buffer = buffer->next;
		}
		data->buf = NULL;
	}
}

static void	heredoc(int fd, char *eof, char **cmd, size_t i)
{
	char	*inpt;
	t_data	*data;

	data = get_data();
	data->heredoc = true;
	while (data->heredoc == true)
	{
		inpt = readline("> ");
		memg(MALLOC, 0, inpt, EXECV);
		if (ft_strncmp(eof, inpt, ft_strlen(eof)) != 0)
			writeif_fd(fd, inpt, data->heredoc);
		else
		{
			data->heredoc = false;
			writeif_fd(fd, inpt, data->heredoc);
		}
	}
	while (cmd[i] && cmd[i + 1])
	{
		cmd[i] = cmd[i + 1];
		i++;
	}
	cmd[i] = NULL;
}

void	checkfor_heredoc(t_lst *cmd_lst)
{
	size_t	i;
	long	rdoc;

	i = 0;
	rdoc = -1;
	while (cmd_lst && cmd_lst->cmd && cmd_lst->cmd[i])
	{
		if (cmd_lst->cmd[i]
			&& ft_strncmp(cmd_lst->cmd[i], "<<", ft_strlen("<<") + 1) == 0)
			rdoc = i;
		i++;
	}
	if (rdoc >= 0 && cmd_lst && cmd_lst->cmd
		&& cmd_lst->cmd[rdoc] && cmd_lst->cmd[rdoc + 1])
	{
		heredoc(cmd_lst->fd_out, cmd_lst->cmd[rdoc + 1], cmd_lst->cmd, rdoc);
		cmd_lst->exec = false;
	}
	else if (rdoc >= 0 && cmd_lst && cmd_lst->cmd
		&& cmd_lst->cmd[rdoc] && cmd_lst->cmd[rdoc + 1] == NULL)
		ft_putstr_fd("minishell:"
			"syntax error near unexpected token `newline'\n", 2);
}
