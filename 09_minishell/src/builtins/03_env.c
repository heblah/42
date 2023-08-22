/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:51:20 by awallet           #+#    #+#             */
/*   Updated: 2022/12/14 17:02:17 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

void	env(t_lst *env, t_bool isexport)
{
	while (env != NULL && *(char *)env->cmd)
	{
		if (isexport)
			printf("declare -x %s\n", (char *)env->cmd);
		else
			printf("%s\n", (char *)env->cmd);
		env = env->next;
	}
}

static void	set_pwd(t_data *data)
{
	char	*var;

	var = memg(MALLOC, (PATH_MAX + 4) * sizeof(char), NULL, OTHER);
	if (var == NULL)
		return (perror("ini_env"));
	ft_strlcpy(var, "PWD=", 5);
	getcwd(var + 4, PATH_MAX);
	ft_addback(&data->env, (char **)var, OTHER);
}

static void	update_shlvl(t_data *data)
{
	int		shval;
	char	*shlvl;

	if (getenv("SHLVL") != NULL)
	{
		shval = ft_atoi(getenv("SHLVL")) + 1;
		shlvl = ft_itoa(shval);
		memg(MALLOC, 0, shlvl, OTHER);
		shlvl = ft_strjoin("SHLVL=", shlvl);
		if (shlvl == NULL)
			return (ft_putstr_fd("Error updating SHLVL.\n", 2));
		memg(MALLOC, 0, shlvl, OTHER);
		export(data, shlvl);
	}
}

t_lst	*init_env(t_data *data)
{
	extern char	**environ;
	char		*var;
	size_t		len;
	size_t		i;

	i = 0;
	len = 0;
	data->env = NULL;
	while (*environ && *(environ + i))
	{
		len = ft_strlen(environ[i]);
		var = memg(MALLOC, (len + 1) * sizeof(char), NULL, OTHER);
		if (var == NULL)
			return (perror("ini_env"), NULL);
		ft_strlcpy(var, environ[i], len + 1);
		ft_addback(&data->env, (char **)var, OTHER);
		i++;
	}
	update_shlvl(data);
	if (*environ == NULL)
		set_pwd(data);
	return (data->env);
}
