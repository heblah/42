/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:02:18 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/05 14:37:16 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_test
{
	char		c;
	short int	littlen; //+1
	int			n; //+3
	long		l; //+4
}				t_test;

int	main(void)
{
	char	*c;

	c = malloc(10 * sizeof(char));
	printf("Adresses depending on casting :\n");
	printf("c\t\t\t=\t%p\n", c);
	printf("c+1\t\t\t=\t%p\n", c + 1);
	printf("(int *)(c + 1)\t\t=\t%p\n", (int *)(c + 1));
	printf("(int *)c + 1\t\t=\t%p\n", (int *)c + 1);

	t_test	*test;

	test = malloc(1 * sizeof(t_test));
	test->c = 'a';
	test->littlen = 147;
	test->n = 9999;
	test->l = test->n * test->n;

	printf("\nStruct addresses and values  :\n");
	printf("t_test\t\t\t=\t%p\n", test);
	printf("&t_test->c\t\t=\t%p\n", &test->c);
	printf("&t_test->littlen\t=\t%p\n", &test->littlen);
	printf("&t_test->n\t\t=\t%p\n", &test->n);
	printf("&t_test->l\t\t=\t%p\n", &test->l);
	printf("t_test->c\t\t=\t%c\n", test->c);
	printf("t_test->littlen\t\t=\t%d\n", test->littlen);
	printf("t_test->n\t\t=\t%d\n", test->n);
	printf("t_test->l\t\t=\t%lu\n", test->l);

	printf("\nGetting the struct components casting it :\n");
	printf("(char *)test->c\t\t\t=\t%c\n", (char)*(char *)test);
	printf("*(short int *)((char *)test + 2)=\t%i\n", *(short int *)((char *)test + 2));
	printf("*(int *)((char *)test + 4)\t=\t%i\n", *(int *)((char *)test + 4));
	printf("*(long *)((char *)test + 8)\t=\t%i\n", *(long *)((char *)test + 8));
	
	free(c);
	free(test);
	return (0);
}
