/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:28:49 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/26 19:57:21 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

int	main(void)
{
	t_data	data __attribute__((unused));

	init_data(&data);
	data.input = prompt();
	prompt();
	return (0);
}

int	init_data(t_data *data)
{
	data->prv_dir = NULL;
	data->cur_dir = NULL;
	data->input = NULL;
	return (0);
}
