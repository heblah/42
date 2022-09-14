/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:01:15 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/14 17:43:38 by halvarez         ###   ########.fr       */
/*   Updated: 2022/08/25 17:11:57 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (ft_printf("Error.\n"));
	else
	{
		stack = parser((const int)argc, (const char **)argv);
		//sort(&stack, a);
		print_stack(stack);
		ft_printf("stack a is sorted = %d\t\t", is_sorted(&stack, a));
		ft_printf("count=%d\n", stack->count);
		//ft_printf("size=%d\n", stack->a_size);
	}
	free_stack(&stack);
	return (0);
}
