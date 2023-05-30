/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/06 16:20:02 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_print(void);

int	main(void)
{
	ft_print();
	ft_print();
	ft_print();
	ft_print();
	ft_print();
	return (0);
}

void	ft_print(void)
{
	static int	n = 0;

	printf("n = %d\n", n);
	n += 1;
}
