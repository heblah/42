/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_ftprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:39:24 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/26 16:39:23 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

void	*print_error(char *s, int line, char *file)
{
	ft_printf("%s\n"
		"Error detected line %d in the file \"%s\"\n",
		s, line, file);
	return (NULL);
}

void	print_index(t_stack *stack)
{
	size_t	lena;
	size_t	lenb;

	lena = lst_len(stack->a);
	lenb = lst_len(stack->b);
	ft_printf("Index a :\t| Index b :\t\n");
	while (lena > 0 || lenb > 0)
	{
		if (lena > 0)
		{
			ft_printf("  %d\t\t|", stack->a->index);
			stack->a = stack->a->next;
			lena--;
		}
		else
			ft_printf("\t\t|");
		if (lenb > 0)
		{
			ft_printf("  %d\t\t\n", stack->b->index);
			stack->b = stack->b->next;
			lenb--;
		}
		else
			ft_printf("\t\t\n");
	}
}

void	print_stack(t_stack *stack)
{
	size_t	lena;
	size_t	lenb;

	lena = lst_len(stack->a);
	lenb = lst_len(stack->b);
	ft_printf("Stack a :\t| Stack b :\t\n");
	while (lena > 0 || lenb > 0)
	{
		if (lena > 0)
		{
			ft_printf("  %d\t\t|", stack->a->n);
			stack->a = stack->a->next;
			lena--;
		}
		else
			ft_printf("\t\t|");
		if (lenb > 0)
		{
			ft_printf("  %d\t\t\n", stack->b->n);
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
