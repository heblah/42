/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:01:15 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/12 15:51:09 by halvarez         ###   ########.fr       */
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
	list_addback(&stack->a, 15000);

	list_addback(&stack->b, 0);
	/*
	list_addback(&stack->b, -5);
	list_addback(&stack->b, -10);
	print_1stack(stack->b, 'b');
	*/
	print_2stack(stack);

	ft_printf("\nsa :\n");
	ft_sa(&stack, printmv);
	print_2stack(stack);

	ft_printf("\nra :\n");
	ft_ra(&stack, printmv);
	print_2stack(stack);

	ft_printf("\nrra :\n");
	ft_rra(&stack, printmv);
	print_2stack(stack);

	ft_printf("\npa :\n");
	ft_pa(&stack, printmv);
	print_2stack(stack);

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
