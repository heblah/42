/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:25:58 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/17 09:19:00 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define CMD(x) "/bin/"(#x)
#define HLP(x) CMD(x)
#define EXC(x) HLP(x)

int	main(int argc __attribute__((unused)), char **argv)
{
	while (*argv)
		printf("%s\n", *argv++);
	return (0);
}
