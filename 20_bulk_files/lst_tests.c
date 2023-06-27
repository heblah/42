/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:01:57 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/13 15:03:29 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_lst
{
	char			*content;
	int				x;
	struct s_lst	*next;
}					t_lst;

void	freelst(t_lst *lst)
{
	t_lst	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst->content);
		free(lst);
		lst = tmp;
	}
}

t_lst *lstadd(t_lst *lst, t_lst *new)
{
	t_lst	*tmp;

	if (lst)
	{
		tmp = lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		lst = new;
	return (lst);
}

int main(void)
{
	char	*s1, *s2;
	t_lst	*lst1, *lst2, *first;

	first = NULL;
	s1 = malloc(10 * sizeof(char));
	lst1 = malloc(sizeof(t_lst));
	lst1->content = s1;
	lst1->x = 1;
	first = lstadd(first, lst1);

	s2 = malloc(10 * sizeof(char));
	lst2 = malloc(sizeof(t_lst));
	lst2->content = s2;
	lst2->x = 2;
	first = lstadd(first, lst2);
	freelst(first);
	return (0);
}
