/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:17:32 by halvarez          #+#    #+#             */
/*   Updated: 2023/04/23 16:13:45 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP 

template <typename T>
void	iter(const T * array, const size_t size, void (*f)(const T & elem))
{
	size_t	i = 0;

	while (i < size)
	{
		(*f)(array[i]);
		i++;
	}
	return;
}

#endif /* ITER_HPP */
