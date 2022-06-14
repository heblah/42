/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:24:38 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/31 18:15:49 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*elem;

	i = 0;
	elem = ft_create_elem(strs[i]);
	while (strs[i] && size > i)
	{
		ft_list_push_front(&elem, strs[i]);
		i++;
	}	
	return (elem);
}

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(1 * sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->next = NULL;
	elem->data = data;
	return (elem);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_elem;

	if (*begin_list)
	{
		new_elem = ft_create_elem(data);
		new_elem->next = *begin_list;
		*begin_list = new_elem;
	}
	else
		*begin_list = ft_create_elem(data);
}

int	main(void)
{
	t_list	*elem;
	char **strs;

	
}
