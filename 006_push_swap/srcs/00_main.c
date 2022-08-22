/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:01:15 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/22 17:36:32 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

/*
int	main()
{
	t_stack	*stack;

	stack = init_stack();
	if (!stack)
		return (-1);
	lst_addback(&stack->a, 50);
	lst_addback(&stack->a, 100);
	lst_addback(&stack->a, 150);
	lst_addback(&stack->a, 200);

	lst_addback(&stack->b, 0);
	lst_addback(&stack->b, -5);
	lst_addback(&stack->b, -10);
	lst_addback(&stack->b, -15);
	ft_printf("\nOriginal stacks :\n");
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

	free_stack(&stack);
	exit (4);
	perror("test");
	return (0);
}*/
int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (ft_printf("Error.\n"));
	else
	{
		stack = parser((const int)argc, (const char **)argv);
		ft_printf("\npa || pb :\n");
		ft_pb(&stack, printmv);
		print_2stack(stack);
	}
	free_stack(&stack);
	return (0);
}
