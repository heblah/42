/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:21:23 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/06 19:08:41 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

void	echo(char **str)
{
	int		i;
	t_bool	new_line;

	i = 0;
	new_line = true;
	while (*(str + ++i))
	{
		if (ft_strncmp("-n", *(str + 1), 2) == 0)
		{
			new_line = false;
			write(1, *(str + (i + 1)), ft_strlen(*(str + (i + 1))));
		}
		else
			write(1, *(str + i), ft_strlen(*(str + i)));
		if (*(str + (i + 1)))
			write(1, " ", 1);
	}
	if (new_line)
		write(1, "\n", 1);
}
