/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:05:38 by halvarez          #+#    #+#             */
/*   Updated: 2022/11/17 17:08:33 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

void	*pwd(void)
{
	char	cdir[PATH_MAX];

	getcwd(cdir, PATH_MAX);
	write(1, cdir, strlen(cdir));
	write(1, "\n", 1);
	return (NULL);
}
