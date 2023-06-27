/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:38:16 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/10 17:36:55 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_combn(int n)
{
	char	*array;
	int	i;
	int j;
	int k;

	i = 0;
	array = "012345678";
	while ( i < n )
	{
		j = 0;
		while ( j <= 9 )
		{
			if (j > i)
			{
				array[n - i] = array[n - i] + j;
				k = -1;
				while (++k < n)
					ft_putchar( array[k] );
			}
			j++;
		}
		i++;
	} 	
}
