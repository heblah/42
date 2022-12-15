/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:28:49 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/14 16:39:59 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

int	main(void)
{
	t_data	*data;

	init_data(&data);
	prompt(data);
	return (0);
}

//(*data)->nb_cmds = 0; /* probably unused, to uncomment is nedded */
int	init_data(t_data **data)
{
	*data = get_data();
	(*data)->garbage = NULL;
	(*data)->lexer = NULL;
	(*data)->parser = NULL;
	(*data)->cmd_lst = NULL;
	(*data)->env = init_env(*data);
	(*data)->status = 0;
	(*data)->isminishell = false;
	(*data)->instance = false;
	(*data)->run = true;
	(*data)->heredoc = false;
	(*data)->buf = NULL;
	return (0);
}

void	*init_tokentab(t_token *token)
{
	int	size;
	int	i;

	i = 0;
	size = 13;
	token = memg(MALLOC, size * sizeof(t_token), NULL, INIT);
	if (token == NULL)
		return (perror("Init token"), NULL);
	while (i < size)
	{
		*(token + i) = i;
		i++;
	}
	return (token);
}
