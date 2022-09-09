/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:01:15 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/09 15:46:52 by halvarez         ###   ########.fr       */
/*   Updated: 2022/08/25 17:11:57 by halvarez         ###   ########.fr       */
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
	ft_swap(&stack, a, print);
	ft_swap(&stack, b, print);
	print_2stack(stack);

	ft_printf("\nra & br :\n");
	ft_rotate(&stack, a, print);
	ft_rotate(&stack, b, print);
	print_2stack(stack);

	ft_printf("\nrra & rrb :\n");
	ft_revrotate(&stack, a, print);
	ft_revrotate(&stack, b, print);
	print_2stack(stack);

	ft_printf("\npa & pb :\n");
	ft_push(&stack, b, print);
	ft_rr(&stack);
	print_2stack(stack);
	ft_printf("count = %d\n", stack->count);

	free_stack(&stack);
	return (0);
}
*/

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (ft_printf("Error.\n"));
	else
	{
		stack = parser((const int)argc, (const char **)argv);
		sort(&stack, a);
		print_stack(stack);
		ft_printf("stack a is sorted = %d\t\t", is_sorted(&stack, a));
		ft_printf("count=%d\n", stack->count);
		//ft_printf("size=%d\n", stack->a_size);
	}
	free_stack(&stack);
	return (0);
}
