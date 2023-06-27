/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/09 11:19:32 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("argv\t= %p\n", argv);
		printf("*argv\t= %p\n", *argv);
		printf("argv[0]\t= %p\n", argv[0]);
		printf("argv[1]\t= %p\n", argv[1]);
		printf("argv[2]\t= %p\n", argv[2]);
		printf("argv[3]\t= %p\n", argv[3]);

		argv++;
		printf("\nargv++\n");
		printf("argv\t= %p\n", argv);
		printf("*argv\t= %p\n", *argv);

		argv++;
		printf("\nargv++\n");
		printf("argv\t= %p\n", argv);
		printf("*argv\t= %p\n", *argv);

		argv++;
		printf("\nargv++\n");
		print("argv\t= %p\n", argv);
		printf("*argv\t= %p\n", *argv);
	}
	return (0);
}
