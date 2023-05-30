/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:35:36 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/31 18:43:38 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	int		i;
	t_list	tmp;

	i = 0;
	tmp = begin_list;
	while (i <= nbr)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
