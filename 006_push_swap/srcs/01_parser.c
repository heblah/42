/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:08:11 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/11 11:09:53 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

int	is_int(int c)
{
	if (c >= 0 && c <= '9' || c == '-')
		return (1);
	return (0);
}

t_list	*one_arg_parser(const char *s)
{
	t_list	*first;

	init_first(&first);
	while (*s)
	{
		while (*s && *s == ' ')
			s++;
		list_addback(&first, ft_atoi(s));
		while (*s && is_int(*s))
			s++;
	}
	return (first);
}
