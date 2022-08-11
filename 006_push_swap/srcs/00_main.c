/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:01:15 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/11 10:16:12 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{

	}
	else
	{
		ft_printf("Error.\n");
		return (-1);
	}
	return (0);
}

void	*print_error(char *s, int line, char *file)
{
	ft_printf("%s\n"
		"Error detected line %d in the file \"%s\"\n",
		s, line, file);
		return (NULL);
}
