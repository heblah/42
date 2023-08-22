/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:18:09 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/14 09:59:31 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

static void	path_error(char *cmd, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(msg, 2);
}

static char	**get_envpath(void)
{
	t_lst	*env;
	t_data	*data;
	char	**path;
	char	*key;
	int		i;

	data = get_data();
	env = data->env;
	if (env != NULL)
	{
		i = 0;
		key = "PATH=";
		while (env != NULL && ft_strncmp(key, (char *)env->cmd, 5) != 0)
			env = env->next;
		if (env)
		{
			path = ft_split((char *)env->cmd + ft_strlen(key), ':');
			if (path != NULL)
				return (add2garbage((void **)path, EXECV), path);
		}
	}
	return (NULL);
}

static char	*cmdjoin(char *path, char *cmd)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*dest;

	len = ft_strlen(path) + 1 + ft_strlen(cmd);
	dest = memg(MALLOC, (len + 1) * sizeof(char), NULL, EXECV);
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (*(path + j) && i < len)
		*(dest + i++) = *(path + j++);
	if (i < len)
		*(dest + i++) = '/';
	j = 0;
	while (cmd && *(cmd + j) && i < len)
		*(dest + i++) = *(cmd + j++);
	*(dest + i) = '\0';
	return (dest);
}

static char	*get_cmdpath(t_lst *cmd_lst)
{
	t_data	*data;
	char	*cmd_path;
	char	**path;
	int		i;

	data = get_data();
	path = get_envpath();
	if (path && !cmd_lst->internal && ft_isalnum(cmd_lst->cmd[0][0]) == 1)
	{
		i = 0;
		while (*(path + i))
		{
			cmd_path = cmdjoin(path[i], cmd_lst->cmd[0]);
			if (cmd_path == NULL)
				return (NULL);
			if (access(cmd_path, F_OK | X_OK) == 0)
				return (cmd_path);
			memg(FREE, 0, cmd_path, EXECV);
			i++;
		}
		return (data->status = 127, cmd_lst->exec = false,
			path_error(*cmd_lst->cmd, ": command not found\n"), NULL);
	}
	return (NULL);
}

int	get_pathes(t_lst *cmd_lst)
{
	char	*cmd_path;
	char	*tmp;

	while (cmd_lst != NULL)
	{
		cmd_lst->internal = check_internal(cmd_lst);
		if (access(cmd_lst->cmd[0], F_OK | X_OK) == 0)
			cmd_lst = cmd_lst->next;
		else
		{
			cmd_path = get_cmdpath(cmd_lst);
			if (cmd_path != NULL)
			{
				tmp = *(cmd_lst->cmd + 0);
				*(cmd_lst->cmd + 0) = cmd_path;
				memg(FREE, 0, tmp, EXECV);
			}
			cmd_lst = cmd_lst->next;
		}
	}
	return (0);
}
