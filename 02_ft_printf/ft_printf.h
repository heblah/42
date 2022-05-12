/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:04:13 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/12 18:06:32 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>

/*structures de flags*/
typedef struct	s_flag
{
	int	percent;
	int	sharp;
	int blank;
	int	plus;
}		t_f;
/*structures de conversions*/
typedef struct	s_conv
{
	int	c;
	int	s;
	int	p;
	int	d;
	int	i;
	int	u;
	int	x;
	int	X;
	int	%;
}	

/*fonctions ft_print.c*/
int		is_conv(char *sub_s);
int		is_flagged_conv(char *sub_s);
#endif
