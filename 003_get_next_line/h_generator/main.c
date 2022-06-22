/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:42:55 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/22 12:25:39 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"
#include "hgenerator.h"

#define CHILD		0
#define FILE_BUF	500

int	main(int argc __attribute__((unused)), char **argv)
{
	char	**files_name;
	int		nbfiles;
	int		hfd;

	if (argc != 2)
	{
		printf("Only one argument is necessary : the name of the header");
		return (-1);
	}
	nbfiles = 0;
	files_name = NULL;
	hfd = create_header(argv[1]);
	files_name = get_files_data(&nbfiles);
	header_writing(hfd, argv[1], files_name, nbfiles);
	freedata(files_name);
	return (0);
}

void	header_writing(int hfd, char *h_name, char **files_name, int nbfiles)
{
	header_protection(hfd, h_name);
	header_includes(hfd);
	header_prototypes(hfd, files_name, nbfiles);
	header_ending(hfd);
}

int	create_header(char *h_name)
{
	int	hfd;

	hfd = open(h_name, O_CREAT | O_APPEND | O_RDWR | S_IRWXU);
	if (hfd == -1)
		hfd = open(h_name, O_TRUNC | O_APPEND | O_RDWR | S_IRWXU);
	return (hfd);
}

void	freedata(char **files_name)
{
	int	i;

	i = 0;
	while (files_name[i])
	{
		free(files_name[i]);
		files_name[i] = NULL;
		i++;
	}
	free(files_name);
	files_name = NULL;
}
