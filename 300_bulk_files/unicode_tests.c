/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:48:17 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/05 17:18:14 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
	return (0);
}
