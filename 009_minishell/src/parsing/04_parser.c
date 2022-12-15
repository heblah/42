/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:00:21 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/12 15:43:44 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

static t_bool	multiple_var(char *cmd)
{
	size_t	i;
	size_t	dollar;

	i = 0;
	dollar = 0;
	while (*(cmd + i))
	{
		if (*(cmd + i) == '$')
		{
			dollar++;
			if (dollar > 1)
				return (true);
		}
		i++;
	}
	return (false);
}

static void	*get_multivar(char *arg)
{
	char	**var;
	char	*varstr;
	size_t	i;

	i = 0;
	varstr = NULL;
	var = ft_split(arg, '$');
	if (var == NULL)
		return (NULL);
	add2garbage((void **)var, PARSE);
	while (*(var + i))
	{
		if (getenv(var[i]) != NULL)
			var[i] = getenv(var[i]);
		else
		{
			var[i] = ft_strjoin("$", var[i]);
			memg(MALLOC, 0, var[i], PARSE);
		}
		i++;
	}
	varstr = joinvar(var);
	if (varstr == NULL)
		return (NULL);
	return (varstr);
}

void	*cmd_checker(char **cmd, t_state state, size_t i)
{
	t_data	*data;
	char	*newstr;

	data = get_data();
	if (cmd[i][0] == '$' && cmd[i][1] == '?')
	{
		newstr = ft_itoa(data->status % 255);
		memg(MALLOC, 0, newstr, OTHER);
		if (cmd[i][2])
			return (newstr = ft_strjoin(newstr, cmd[i] + 2),
				memg(MALLOC, 0, newstr, OTHER), cmd[i] = newstr, data);
		cmd[i] = newstr;
	}
	else if (cmd[i][0] == '$' && state != S_SINQUOTE
		&& multiple_var(cmd[i]) == false && getenv(cmd[i] + 1) != NULL)
			cmd[i] = getenv(cmd[i] + 1);
	else if (cmd[i][0] == '$' && state != S_SINQUOTE
		&& multiple_var(cmd[i]) == true)
	{
		cmd[i] = get_multivar(cmd[i]);
		if (cmd[i] == NULL)
			return (ft_putstr_fd("minishell: error expanding variables\n", 2),
				data->status = 1, NULL);
	}
	return (data);
}

/*
static char	**split_keyvar(t_lst *cmd_lst, size_t i)
{
	char	**var;
	char	*var_tmp;
	size_t	len;
	size_t	j;

	j = 0;
	var = ft_split(cmd_lst->cmd[i], '$');
	if (var == NULL)
		return (ft_putstr_fd("Error on malloc during var expansion.\n", 2),
			NULL);
	add2garbage((void **)var, PARSE);
	j = 0;
	while (*(var + j))
	{
		len = ft_strlen(var[j]);
		var_tmp = memg(MALLOC, (len + 2) * sizeof(char), 0, PARSE);
		if (var_tmp == NULL)
			return (NULL);
		ft_strlcpy(var_tmp, var[j], len + 1);
		var_tmp[len] = '=';
		var_tmp[len + 1] = '\0';
		var[j++] = var_tmp;
	}
	return (var);
}

static char	**alloc_value(char **key)
{
	char	**value;
	size_t	i;

	i = 0;
	if (key == NULL)
		return (NULL);
	while (*(key + i))
		i++;
	value = memg(MALLOC, (i + 1) * sizeof(char *), NULL, PARSE);
	if (value == NULL)
		return (NULL);
	while (i != 0)
		*(value + i--) = NULL;
	*value = NULL;
	return (value);
}

static char	*valuecpy(char *var_env, size_t keylen)
{
	char	*value;

	value = memg(MALLOC, (ft_strlen(var_env) + 1) * sizeof(char), NULL, PARSE);
	if (value == NULL)
		return (NULL);
	if (var_env == NULL)
		*value = '\0';
	else
		ft_strlcpy(value, var_env + keylen,
			ft_strlen(var_env) - (keylen - 1));
	return (value);
}

static char	**key2value(t_data *data, char **key)
{
	char	**value;
	t_lst	*env;
	size_t	keylen;
	size_t	i;

	i = 0;
	value = alloc_value(key);
	if (value == NULL)
		return (NULL);
	while (key && *(key + i))
	{
		env = data->env;
		keylen = ft_strlen(key[i]);
		while (env && ft_strncmp(key[i], (char *)env->cmd, keylen) != 0)
			env = env->next;
		if (env)
			value[i] = valuecpy((char *)env->cmd, keylen);
		else
			value[i] = valuecpy(NULL, keylen);
		if (value[i] == NULL)
			return (NULL);
		i++;
	}
	return (value);
}

void	expand_env(t_lst *cmd_lst, size_t i)
{
	t_data	*data;
	char	**var;
	char	*strvar;

	data = get_data();
	var = split_keyvar(cmd_lst, i);
	if (**var == '?')
	{
		strvar = ft_itoa(data->status);
		cmd_lst->cmd[i] = strvar;
		memg(MALLOC, 0, strvar, OTHER);
		return ;
	}
	var = key2value(data, var);
	if (var == NULL)
		return ;
	strvar = joinvar(var);
	if (strvar == NULL)
		return ;
	cmd_lst->cmd[i] = strvar;
}
*/
