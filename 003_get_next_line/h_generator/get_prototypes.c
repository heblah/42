/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prototypes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:57:45 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/21 18:47:54 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"
#include "hgenerator.h"

void	write_file_line(int hfd, char *files_name)
{
	int	width;

	width = 80 - 3;
	write (hfd, "/* ", 3);
	width -= 3;
	while (*files_name)
	{
		write(hfd, files_name, 1);
		files_name++;
		width--;
	}
	write(hfd, " ", 1);
	width--;
	while (width-- > 0)
		write(hfd, "=", 1);
	write (hfd, " */\n", 4);
}

void	get_next_file(int hfd, char *files_name, int nbfiles)
{

}
