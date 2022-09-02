/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_ftprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:39:24 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/02 11:24:27 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

/*
void	*print_error(char *s, int line, char *file)
{
	ft_printf("%s\n"
		"Error detected line %d in the file \"%s\"\n",
		s, line, file);
	return (NULL);
}
*/

void	print_stack(t_stack *stack)
{
	size_t	lena;
	size_t	lenb;

	lena = lst_len(stack->a);
	lenb = lst_len(stack->b);
	ft_printf("Stack a :\t\t| Stack b :\t\n");
	while (lena > 0 || lenb > 0)
	{
		if (lena > 0)
		{
			ft_printf("  %d\t%d\t\t|", stack->a->index, stack->a->n);
			stack->a = stack->a->next;
			lena--;
		}
		else
			ft_printf("\t\t\t|");
		if (lenb > 0)
		{
			ft_printf("  %d\t%d\t\t\n", stack->b->index, stack->b->n);
			stack->b = stack->b->next;
			lenb--;
		}
		else
			ft_printf("\t\t\n");
	}
}

/*Do no print on stderr*/
void	*ft_exit(t_stack **stack, int status)
{
	if (status == 1)
		ft_printf("Error : wrong input.\n");
	else if (status == 2)
		ft_printf("Error : there is at least one duplicate.\n");
	if (*stack)
		free_stack(stack);
	exit(status);
	return (0);
}

/*
void	print_moves(t_stack **stack, char *mv, int select_stack)
{
	char	*new_mv[4
	if ()
	if ()
}
*/
