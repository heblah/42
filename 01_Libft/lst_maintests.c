/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_maintests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:52:36 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/10 12:38:47 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main()
{
	t_list	*first;

	/*creation du "premier element" de la liste*/
	first = ft_lstnew("aaa");
	ft_putstr_fd("Element en queue de liste :", 1);
	ft_putendl_fd(first->content, 1);

	/*creation et ajout d'un nouvel element en queue de liste*/
	t_list *new;
	new =  ft_lstnew("bbb");
	ft_lstadd_front(&first, new);
	ft_putstr_fd("Nouvel element de la liste:", 1);
	ft_putendl_fd(first->content, 1);
	new = ft_lstnew("tete de liste");
	ft_lstadd_front(&first, new);
	ft_putstr_fd("Element en tete de liste :", 1);
	ft_putendl_fd(first->content, 1);
	ft_putstr_fd("Element suivant la tete de liste :", 1);
	ft_putendl_fd(first->next->content, 1);

	/*calcul de la taille de la liste*/
	ft_putstr_fd("Liste de taille=", 1);
	ft_putnbr_fd(ft_lstsize(first), 1);
	write(1, "\n", 1);

	/*Affiche le dernier element de la liste*/
	t_list	*printlast;

	printlast = ft_lstlast(first);
	ft_putstr_fd("Afficher l'element en queue de liste :", 1);
	ft_putendl_fd(printlast->content, 1);

	/*Ajoute un element en queue de liste*/
	t_list *newlast;

	newlast = ft_lstnew("nvl queue de liste");
	ft_lstadd_back(&first, newlast);
	printlast = ft_lstlast(first);
	ft_putstr_fd("Afficher l'element en queue de liste :", 1);
	ft_putendl_fd(printlast->content, 1);
	return (0);
}
