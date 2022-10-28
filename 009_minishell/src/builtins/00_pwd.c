/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:05:38 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/19 15:15:47 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

void	*pwd(void)
{
	char	cdir[256];

	getcwd(cdir, 256);
	write(1, cdir, ft_strlen(cdir));
	write(1, "\n", 1);
	return (NULL);
}
