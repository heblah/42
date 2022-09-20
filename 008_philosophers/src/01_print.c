/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:00:43 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/20 09:53:53 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	print_manual(int output)
{
	printf("Please enter unsigned int as follow :\n"
		"N_of_philo time_to_die time_to_eat time_to_sleep "
		"[optional]N_of_meals_per_philo\n");
	return (output);
}
