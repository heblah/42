/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:32:01 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/28 10:41:49 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct s_segment t_segment;
struct	s_segment
{
	int 		len;
	int			col;
	int			row;
	t_segment	*next;
};
#endif
