/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:08:11 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/16 19:27:13 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

int	is_valid_char(int c)
{
	if ((c >= 0 && c <= '9') || c == '-' || c == ' ')
		return (1);
	return (0);
}
int	is_valid_lst(const char *s)
{
	while (*s && is_valid_char(*s))
		s++;
	if (*s == '\0')
		return (1);
	else
		return (0);
}

t_stack	*parser(const int argc, const char **argv)
{
	char	**s;
	t_stack	*stack;
	int		nb;
	int		i;

	i= -1;
	stack = init_stack();
	ft_printf("argv[1]=%s\n", argv[1]);
	if (argc == 2)
		s = ft_split(argv[1], ' ');
	else
		s = (char **)(argv + 1);
	ft_printf("s[0]=%s\n", s[2]);
	while (s && *(s + ++i) && argc - i > 0)
	{
		nb = ft_atoi(*(s + i));
		if (is_double(stack->a, nb))
			return (free_stack(&stack));
		lst_addback(&stack->a, nb);
	}
	return (stack);
}
