/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigraph_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/05 17:01:48 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//Compile with -trigraphs flag
int	main(void)
{
	write(1, "??=\n", 2);
	write(1, "??(\n", 2);
	write(1, "??/\n", 2); //chelou
	write(1, "??)\n", 2);
	write(1, "??'\n", 2);
	write(1, "??<\n", 2);
	write(1, "??!\n", 2);
	write(1, "??>\n", 2);
	write(1, "??-\n", 2);
	return (0);
}
