/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_managing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:52:48 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/09 15:44:33 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"
#include "hgenerator.h"

int	main(void)
{
	int		fd;
	char	name[]__attribute__((unused)) = "hgentest.h";
	//int		wr;

	fd = open(name, O_CREAT | O_APPEND | O_RDWR | S_IRWXU);
	return (0);
}

char	*get_files_names(void)
{
	char	*find_path;
	char	*find_cmd;
	char	*find_cur_dir;
	char	*find_c_files;
	int		

	find_path = "/bin/find"
	find_cmd = "find ";
	find_cur_dir = "! \\( -type d ! -name . -prune\\ ) ";
	find_c_files = "-type f -name '*.c'";
	execv(find_path, find_path, find_cmd, find_cur_dir, find_c_files, 
		(char *)0);
	/*pipe -> fork -> utiliser la sortir pour avoir  */
}
