/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:21:23 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/26 20:33:39 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define "t_minishell.h"
#define "ft_moinishell.h"

int	echo(char **str)
{
	if (ft_strncmp("-n", *str, 3) == 0)
	{
		write(1, *(str + 1), ft_strlen(*(str + 1)));
		write(1, "\n", 1);
	}
	else
		write(1, *str, ft_strlen(*str));
	return (0);
}
