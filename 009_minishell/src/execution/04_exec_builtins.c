/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_exec_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:31:57 by awallet           #+#    #+#             */
/*   Updated: 2022/12/12 15:34:28 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

void	cd_error(char *reason, char *path)
{
	t_data	*data;

	data = get_data();
	data->status = 1;
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("cd: ", 2);
	if (path)
	{
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(reason, 2);
}

t_bool	check_internal(t_lst *lst)
{
	char	*cmd;

	cmd = lst->cmd[0];
	if (!cmd)
		return (false);
	if (ft_strcmp("echo", cmd) == 0)
		return (true);
	else if (ft_strcmp("cd", cmd) == 0)
		return (true);
	else if (ft_strcmp("pwd", cmd) == 0)
		return (true);
	else if (ft_strcmp("exit", cmd) == 0)
		return (true);
	else if (ft_strcmp("unset", cmd) == 0)
		return (true);
	else if (ft_strcmp("export", cmd) == 0)
		return (true);
	else if (ft_strcmp("env", cmd) == 0)
		return (true);
	return (false);
}
