/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:24:59 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/31 10:51:14 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	struct s_list		*next;
	void				*data;
}						t_list;

#endif
