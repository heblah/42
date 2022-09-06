/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:48:17 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/06 17:38:06 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	unsigned char	utf[3];

	utf[0] = 65; //only byte of A
	utf[1] = 195; //=11000011 first byte of é
	utf[2] = 169; //=10101001 second byte of é
	write(1, utf, 3);
	write(1, "\n", 1);

	write(1, utf, 1);
	write(1, utf + 1, 1);
	write(1, utf + 2, 1);
	write(1, "\n", 1);

	write(1, utf, 1);
	write(1, utf + 1, 2);
	write(1, "\n", 1);

	ft_putchar(utf[0]);
	ft_putchar(utf[1]);
	ft_putchar(utf[2]);
	write(1, "\n", 1);
	return (0);
}
