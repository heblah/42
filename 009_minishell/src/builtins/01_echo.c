/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:21:23 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/15 09:37:30 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

void	echo(int fd, char **str)
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
			write(fd, *(str + (i + 1)), ft_strlen(*(str + (i + 1))));
		}
		else
			write(fd, *(str + i), ft_strlen(*(str + i)));
		if (*(str + (i + 1)))
			write(fd, " ", 1);
	}
	if (new_line)
		write(fd, "\n", 1);
}
