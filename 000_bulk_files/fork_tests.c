/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:17:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/14 16:00:01 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	//execl("/bin/ls", "/bin/ls", "-l", (char *)0);
	execl("/bin/find", "/bin/find","-type f -name '*.c'", NULL);
	printf("exec nok\n");
	return (0);
}

/*	find_path = "/bin/find"
	find_cmd = "find ";
	find_cur_dir = "! \\( -type d ! -name . -prune\\ ) ";
	find_c_files = "-type f -name '*.c'";
*/
