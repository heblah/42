/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:28:49 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/31 16:40:28 by halvarez         ###   ########.fr       */
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
	data->input = NULL;
	data->prv_dir = NULL;
	data->cur_dir = NULL;
	init_tokentab(t_token *token);
	data->lst_cmds = NULL;
	return (0);
}

void	*init_tokentab(t_token *token)
{
	int	size;
	int	i;

	i = 0;
	size = 13;
	token = malloc(size * sizeof(t_token));
	if (token == NULL)
		return (perror("Init token"), NULL);
	while (i < size)
	{
		*(token + i) = i;
		i++;
	}
	return (token);
}
