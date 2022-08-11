/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:18:09 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/11 18:56:13 by halvarez         ###   ########.fr       */
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
	ft_printf("1st a=%d\n", stack->a->n);
	ft_printf("2nd a=%d\n", stack->a->next->n);
	ft_printf("3rd a=%d\n", stack->a->next->next->n);
	free_stack(&stack);
	return (0);
}
