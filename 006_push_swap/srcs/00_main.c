/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:01:15 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/16 12:09:11 by halvarez         ###   ########.fr       */
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
	list_addback(&stack->a, 50);
	list_addback(&stack->a, 100);
	/*
	list_addback(&stack->a, 150);
	list_addback(&stack->a, 200);
	*/

	list_addback(&stack->b, 0);
	list_addback(&stack->b, -5);
	/*
	list_addback(&stack->b, -10);
	list_addback(&stack->b, -15);
	*/
	ft_printf("\nOriginal stacks :\n");
	ft_printf("stack a = %p\nstack b = %p\n", stack->a, stack ->b);
	print_2stack(stack);

	ft_printf("\nsa & sb :\n");
	ft_sa(&stack, printmv);
	ft_sb(&stack, printmv);
	print_2stack(stack);

	ft_printf("\nra & br :\n");
	ft_ra(&stack, printmv);
	ft_rb(&stack, printmv);
	print_2stack(stack);

	ft_printf("\nrra & rrb :\n");
	ft_rra(&stack, printmv);
	ft_rrb(&stack, printmv);
	print_2stack(stack);

	ft_printf("\npa & pb :\n");
	ft_pa(&stack, printmv);
	ft_pb(&stack, printmv);
	print_2stack(stack);
	ft_printf("stack a = %p\nstack b = %p\n", stack->a, stack ->b);

	free_stack(&stack);
	return (0);
}
/*
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
*/
