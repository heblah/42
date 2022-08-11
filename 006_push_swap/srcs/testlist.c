/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:18:09 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/11 12:05:22 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

int	main()
{
	t_lst	*first;

	first = NULL;
	printf("len_list=%d\n", list_len(first));
	first = list_addback(&first, 5);
	printf("first n=%d\n", first->n);
	printf("len_list=%d\n", list_len(first));
	first = list_addback(&first, 10);
	printf("2nd n=%d\n", first->next->n);
	printf("len_list=%d\n", list_len(first));
	first = list_addback(&first, 15);
	printf("3rd n=%d\n", first->next->next->n);
	printf("len_list=%d\n", list_len(first));
	printf("3rd previous n=%d\n", first->next->next->previous->n);
	printf("3rd next n=%d\n", first->next->next->next->n);
	first = list_addback(&first, 20);
	printf("4th n=%d\n", first->next->next->next->n);
	printf("len_list=%d\n", list_len(first));
	free_list(&first);
	return (0);
}
