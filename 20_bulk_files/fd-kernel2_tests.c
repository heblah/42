/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd-kernel2_tests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/15 10:14:03 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	str[200];
	int		r;

	r = read(3, str, 10);
	printf("r = %d\n", r);
	printf("str =%s\n", str);
	return (0);
}
