/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:18:09 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/12 09:57:38 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

int	main()
{
	t_stack	*stack;

	stack = init_stack();
	if (!stack)
		return (-1);
	list_addback(&stack->a, 5);
	list_addback(&stack->a, 10);
	list_addback(&stack->a, 15);
	ft_printf("\nstack a :\n");
	print_list(stack->a);

	list_addback(&stack->b, 0);
	list_addback(&stack->b, -5);
	list_addback(&stack->b, -10);
	ft_printf("\nstack b :\n");
	print_list(stack->b);

	ft_printf("\nmv_front :\n");
	mv_front(&stack->a, &stack->b);
	ft_printf("\nPrint stack a : \n");
	print_list(stack->a);
	ft_printf("\nPrint stack b : \n");
	print_list(stack->b);

	free_stack(&stack);
	return (0);
}
