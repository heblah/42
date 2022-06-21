/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:42:55 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/21 18:38:10 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"
#include "hgenerator.h"

#define CHILD		0
#define FILE_BUF	500
#define BUFFER_SIZE 2000

int	main(int argc __attribute__((unused)), char **argv)
{
	char	*h_name;
	char	**files_name;
	int		nbfiles;
	int		hfd;

	nbfiles = 0;
	files_name = NULL;
	h_name = argv[1];
	hfd = create_header();
	header_writing(hfd, h_name);
	files_name = get_files_data(&nbfiles);
}

void	header_writing(int hfd, char *h_name)
{
	header_protection(hfd, h_name);
	header_includes(hfd);
	//header_prototypes
	header_ending(hfd);
}

void	create_header(void)
{
	int	hfd;

	hfd = open(h_name, O_CREAT | O_APPEND | O_RDWR | S_IRWXU);
	if (hfd == -1)
		hfd = open(h_name, O_TRUNC | O_APPEND | O_RDWR | S_IRWXU);
	return (hfd);
}
