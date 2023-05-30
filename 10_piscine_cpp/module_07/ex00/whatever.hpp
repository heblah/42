/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:11:47 by halvarez          #+#    #+#             */
/*   Updated: 2023/04/23 15:50:02 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP 

template <typename T>
void	swap(T & a, T & b)
{
	T	tmp = a;

	a = b;
	b = tmp;
	return;
}

template <typename T>
T	min(const T & a, const T & b)
{
	return ( (a <= b) ? a : b );
}

template <typename T>
T	max(const T & a, const T & b)
{
	return ( (a >= b) ? a : b );
}

#endif /* WHATEVER_HPP */
