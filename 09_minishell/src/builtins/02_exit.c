/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:31:39 by awallet           #+#    #+#             */
/*   Updated: 2022/12/12 10:20:45 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

void	exit_error(char *status, t_data *data)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("exit: ", 2);
	ft_putstr_fd(status, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	memg(PURGE, 0, NULL, 0);
	exit(data->status);
}

void	mn_exit(char *status)
{
	t_data	*data;
	int		exit_status;
	int		new_status;
	int		i;

	i = -1;
	data = get_data();
	ft_putstr_fd("exit\n", 1);
	if (ft_strcmp("-1", status) != 0)
	{
		while (*(status + ++i))
			if (!ft_isdigit(*(status + i)))
				return (data->status = 2, exit_error(status, data));
	}
	exit_status = 0;
	new_status = ft_atoi(status);
	if (new_status < 0)
		exit_status = data->status;
	else
		exit_status = new_status;
	memg(PURGE, 0, NULL, 0);
	exit(exit_status);
}
