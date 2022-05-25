/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_enum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hans </var/spool/mail/hans>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:04:41 by hans              #+#    #+#             */
/*   Updated: 2022/05/25 11:15:41 by hans             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef enum	list
{
	elem0,
	elem1 = 1 << 0,
	elem2 = 1 << 1,
	elem3 = elem1 | elem2
}	flag;

int	ptr_enum(flag *a);

int	main()
{
	flag a;

	//a = elem0;
	ptr_enum(&a);
	return (0);
}

int	ptr_enum(flag *a)
{
	printf("elem0=%d\n", *a);
	*a = elem1;
	printf("elem1=%d\n", *a);
	*a = elem2;
	printf("elem2=%d\n", *a);
	*a = elem3;
	//*a = elem1;
	printf("elem3=%d\n", *a);
	long obj;
	obj = elem1 | elem2;
	printf("obj=%ld\n", obj);
	return (0);
}
