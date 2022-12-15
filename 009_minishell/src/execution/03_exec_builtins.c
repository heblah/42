/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_exec_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:30:53 by awallet           #+#    #+#             */
/*   Updated: 2022/12/15 09:50:12 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

static int	nb_arg(t_lst *lst)
{
	int	count;
	int	i;

	i = 1;
	count = 0;
	while (lst->cmd && *(lst->cmd + i))
	{
		count++;
		i++;
	}
	return (count);
}

static void	ft_error(char *cmd, char *arg, char *error, int type)
{
	t_data	*data;

	data = get_data();
	data->status = 1;
	if (type == 0)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": '", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': No such file or directory", 2);
	}
	else if (type == 1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(error, 2);
	}
	ft_putstr_fd("\n", 2);
	if (ft_strcmp(cmd, "exit") == 0)
		mn_exit("1");
}

static void	internal_cmd_02(t_data *data, t_lst *lst, char *cmd, int args)
{
	int	i;

	if (ft_strcmp("export", cmd) == 0)
	{
		if (args == 0)
			env(lst->fd_out, data->env, true);
		else if (args > 0)
		{
			i = 0;
			while (*(lst->cmd + ++i))
				export(data, lst->cmd[i]);
		}
	}
	if (ft_strcmp("env", cmd) == 0)
	{
		if (args > 0)
			return (ft_error(cmd, lst->cmd[1], NULL, 0));
		env(lst->fd_out, data->env, false);
	}
}

static void	internal_cmd_03(t_data *data, t_lst *lst, char *cmd, int args)
{
	int	i;

	if (ft_strcmp("pwd", cmd) == 0)
		pwd();
	if (ft_strcmp("exit", cmd) == 0)
	{
		if (args > 1)
			return (ft_error(cmd, lst->cmd[1], "Too many arguments", 1));
		else if (args == 1)
			mn_exit(lst->cmd[1]);
		mn_exit("-1");
	}
	if (ft_strcmp("unset", cmd) == 0)
	{
		if (args > 0)
		{
			i = 0;
			while (*(lst->cmd + ++i))
				unset(data, lst->cmd[i]);
		}
		else
			unset(data, NULL);
	}
}

void	internal_cmd(t_lst *lst)
{
	char	*cmd;
	int		args;
	t_data	*data;

	data = get_data();
	if (lst && lst->cmd)
		cmd = lst->cmd[0];
	else
		return ;
	args = nb_arg(lst);
	if (ft_strcmp("echo", cmd) == 0)
		echo(lst->fd_out, lst->cmd);
	else if (ft_strcmp("cd", cmd) == 0)
	{
		if (args > 1)
			return (ft_error(cmd, lst->cmd[1], "Too many arguments", 1));
		cd(lst->cmd[1]);
	}
	internal_cmd_02(data, lst, cmd, args);
	internal_cmd_03(data, lst, cmd, args);
}
