/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 21:01:07 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/10 15:11:54 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int	ft_fonction1(void);

int	main()
{
	printf("printf du main\n");
	ft_fonction1();
	return (0);
}

int	ft_fonction1(void)
{
	printf("printf fct 1 avant fork\n");
	fork();
	printf("printf fct 1 apres fork\n");
	//wait(NULL);
	return (0);
}
