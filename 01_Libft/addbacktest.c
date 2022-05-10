/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addbacktest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:43:54 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/10 18:20:21 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main()
{
	t_list *l;
	t_list *l2;

	l = NULL;
	l2 = NULL;
	ft_lstadd_back(&l, ft_lstnew((void*)1));
	ft_lstadd_back(&l, ft_lstnew((void*)2));
	ft_lstadd_back(&l2, ft_lstnew((void*)3));
	ft_lstadd_back(&l2, ft_lstnew((void*)4));
	ft_lstadd_back(&l, l2);
	if (l->content == (void*)1)
		printf("1 OK\n");
	if (l->next->content == (void*)2)
		printf("2 OK\n");
	if (l->next->next->content == (void*)3)
		printf("3 OK\n");
	if (l->next->next->next->content == (void*)4)
		printf("4 OK\n");
}
