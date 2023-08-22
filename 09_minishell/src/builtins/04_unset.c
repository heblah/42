/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:11:31 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/07 13:39:10 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

static void	unset_error(const char *var)
{
	ft_putstr_fd("unset: ", 2);
	if (!var)
		return (ft_putstr_fd("not enough arguments\n", 2));
	ft_putstr_fd((char *)var, 2);
	ft_putstr_fd(": invalid parameter name\n", 2);
}

void	unset(t_data *data, const char *oldvar)
{
	t_lst	*env_tmp;
	size_t	len_key;
	size_t	i;

	env_tmp = NULL;
	i = 0;
	if (!oldvar)
		return (data->status = 1, unset_error(oldvar));
	while (*(oldvar + i))
		if (ft_isalnum(*(oldvar + i++)) == false)
			return (data->status = 1, unset_error(oldvar));
	len_key = ft_strlen(oldvar);
	if (data->env && ft_strncmp((char *)data->env->cmd, oldvar, len_key) == 0)
		data->env = data->env->next;
	env_tmp = data->env;
	while (env_tmp)
	{
		if (env_tmp->next
			&& ft_strncmp((char *)env_tmp->next->cmd, oldvar, len_key) == 0)
		{
			env_tmp->next = env_tmp->next->next;
		}
		env_tmp = env_tmp->next;
	}
}
