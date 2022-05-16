/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:04:13 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/16 18:04:04 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdarg.h>

/*structures de flags*/
typedef struct	s_flag
{
	int	sharp;/*suivi d'un x ou X*/
	int blank;/*suivi d'un i, d ou u*/
	int	plus;/*suivi d'un i, d ou u*/
}		t_f;

/*fonctions ft_print.c*/
int		ft_printf(const char *s, ...);
int		print_conv(const char *s, int *count, va_list argp);
int		init_flags(const char *s, t_f flag;)
void 	(*print_selecter(const char s, int *count))(t_f, va_list, int *);

/*ft_puthex.c :*/
void	ft_ptr_to_hex(t_f *flag, va_list argp, int *count);
void	ft_long_to_hex(t_f *flag, va_list argp, int *count);
char	*ft_long_flag(t_f *flag, int *count);
void	ft_puthex(unsigned long n, char *base);

/*ft_putnbr.c :*/
void	ft_int_to_nbr(t_f *flag, va_list argp, int *count);
void	ft_uint_to_nbr(t_f *flag, va_list argp, int *count);
void	ft_putnbr(long nb, int *count);

/*ft_putttxt.c :*/
void	ft_putchar(t_f *flag, va_list argp, int *count);
void	ft_putstr(t_f *flag, va_list argp, int *count);
#endif
