/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hgenerator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:14:51 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/22 14:37:20 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"
#include "hgenerator.h"

void	header_protection(int fd, char *name)
{
	name = header_name(name);
	write(fd, "#ifndef ", 9);
	write(fd, name, gnl_strlen(name));
	write(fd, "\n", 1);
	write(fd, "# define ", 9);
	write(fd, name, gnl_strlen(name));
	write(fd, "\n\n", 2);
}

void	header_includes(int fd)
{
	write(fd, "# include <stdlib.h>\n", gnl_strlen("# include <stdlib.h>\n"));
	write(fd, "# include <stdio.h>\n", gnl_strlen("# include <stdio.h>\n"));
	write(fd, "# include <unistd.h>\n", gnl_strlen("# include <unistd.h>\n"));
	write(fd, "# include <fcntl.h>\n", gnl_strlen("# include <fcntl.h>\n"));
	write(fd, "# include <limits.h>\n", gnl_strlen("# include <limits.h>\n"));
}

char	*header_name(char *name)
{
	int	i;

	i = 0;
	while (*(name + i))
	{
		*(name + i) = ft_toupper(*(name + i));
		if (*(name + i + 1) && *(name + i) == '.' && *(name + i + 1) == 'h')
		{
			*(name + i) = '_';
			*(name + i + 1) = 'H';
		}
		i++;
	}
	return (name);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - ('a' - 'A');
	return (c);
}

void	header_ending(int fd)
{
	write(fd, "#endif\n", 7);
}
