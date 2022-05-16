/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:42:00 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/16 12:31:39 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ptintf.h"

ft_ptr_to_hex(t_f *flag, unsigned long n)
{
	char *hex;

	if (!(flag->shap && flag->blank && flag->plus))
	{
		write(1, "0x", 2);
		hex = "0123456789abcdef";
		ft_puthex(n, hex);
	}
}
