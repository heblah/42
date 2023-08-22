/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:45:08 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/14 16:01:03 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

void	do_it_bro(t_data *data, t_lst *lst, int type)
{
	if (type == 0)
	{
		data->instance = false;
		data->isminishell = false;
	}
	else if (type == 1)
	{
		anti_minishell(lst);
		signal(SIGQUIT, sigquit_handler);
	}
}

void	anti_minishell(t_lst *lst)
{
	t_data	*data;

	data = get_data();
	if (ft_strcmp("./minishell", lst->cmd[0]) == 0)
		data->isminishell = true;
	else if (ft_strcmp("minishell", lst->cmd[0]) == 0)
		data->isminishell = true;
}

void	add2garbage(void **ptr, t_label label)
{
	size_t	i;

	i = 0;
	memg(MALLOC, 0, ptr, label);
	while (*(ptr + i))
	{
		memg(MALLOC, 0, *(ptr + i), label);
		i++;
	}
}
