/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:05:03 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/09 18:31:51 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP 

#include <algorithm>

template <typename T>
typename T::const_reference	easyfind(const T & container, const int i)
{
	typename T::const_iterator it = find(container.begin(), container.end(), i);

	if (it == container.end())
		throw std::runtime_error("Error: value is not in the container");
	return ( *it );
}

#endif /* EASYFIND_HPP */
