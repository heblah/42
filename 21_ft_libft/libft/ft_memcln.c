/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcln.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:15:18 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/13 11:20:00 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcln(void *p, size_t n)
{
	unsigned char	*byte;

	byte = p;
	while (n-- > 0)
		*(byte + n) &= ~*(byte + n);
	return (byte);
}
