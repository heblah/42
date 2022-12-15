/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:22:06 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/07 10:10:55 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

static void	export_error(char *var, t_data *data)
{
	ft_putstr_fd("minishell: export: '", 2);
	ft_putstr_fd(var, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	data->status = 1;
}

static size_t	keylen(char *var, t_data *data)
{
	size_t	i;
	size_t	equal;

	i = 0;
	equal = 0;
	if (*(var + i) == '=')
		return (export_error(var, data), 0);
	while (*(var + i) && *(var + i) != '=')
	{
		if (ft_isalnum(var[i]) == 0 && var[i] != '=')
			return (export_error(var, data), 0);
		else if (ft_isalnum(var[i]) == 0 && var[i] == '=')
			equal++;
		i++;
	}
	if (equal > 1)
		return (export_error(var, data), 0);
	return (i);
}

static void	switch_var(t_lst *env, char **oldvar, char *newvar, int *toggle)
{
	*oldvar = (char *)env->cmd;
	env->cmd = (char **)newvar;
	memg(FREE, 0, oldvar, 0);
	*toggle = true;
}

void	*export(t_data *data, char *newvar)
{
	t_lst	*env;
	char	*oldvar;
	size_t	key_len;
	int		toggle;

	newvar = strdup(newvar);
	memg(MALLOC, 0, newvar, OTHER);
	env = data->env;
	key_len = keylen(newvar, data);
	toggle = false;
	if (key_len == 0)
		return (NULL);
	while (env)
	{
		if (ft_strncmp(newvar, (char *)env->cmd, key_len) == 0)
		{
			switch_var(env, &oldvar, newvar, &toggle);
			return ((data->status = 0), newvar);
		}
		env = env->next;
	}
	if (env == NULL && toggle == false)
		ft_addback(&data->env, (char **)newvar, OTHER);
	return (NULL);
}
