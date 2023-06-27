/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:28:58 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/27 16:55:31 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_oandr(char *dico_name, char *dico_str)
{
	int		fd;
	int		rd;
	int		end;

	fd = open(dico_name, O_RDONLY);
	if (fd == -1)
		return (-4);
	rd = read(fd, dico_str, BUF_SIZE);
	if (rd == -1)
		return (-3);
	dico_str[rd] = '\0';
	end = rd;
	rd = read(fd, dico_str, BUF_SIZE);
	if (rd == 0)
	{
		if (close(fd) != -1)
			return (end);
		else
			return (-1);
	}
	return (-2);
}

int	ft_close(int fd)
{
	if (close(fd) == -1)
		return (-1);
	return (0);
}
