/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:39:24 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/12 11:51:22 by halvarez         ###   ########.fr       */
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

void	print_1stack(t_lst *lst, char c)
{
	int	i;
	int	index;

	i = list_len(lst);
	index = 0;
	ft_printf("Stack %c :\n", c);
	while (i-- > 0)
	{
		ft_printf("Elem %d = %d\n", index++, lst->n);
		lst = lst->next;
	}
}

void	print_2stack(t_stack *stack)
{
	int	lena;
	int lenb;

	lena = list_len(stack->a);
	lenb = list_len(stack->b);
	ft_printf("Stack a\t\t|\t\tStack b\n");
	while (lena > 0 || lenb > 0)
	{
		if (lena > 0)
		{
			ft_printf("%d\t\t|", stack->a->n);
			lena--;
		}
		else
			ft_printf("\t\t\t|");
		if (lenb > 0)
		{
			ft_printf("%d\t|\n", stack->b->n);
			lenb--;
		}
		else
			ft_printf("\t\t|\n");
	}
}
