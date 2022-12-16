/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:25:58 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/16 12:15:29 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define CMD(x) "/bin/"(#x)
#define HLP(x) CMD(x)
#define EXC(x) HLP(x)

int	main(void)
{
	char	*s;

	s = "mot1%2$smot2%4$cmot3%4$cmot4";

	printf(s, 9, "test", 10, 92);
	printf("\n---end of line ---");
	return (0);
}
