/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:10:43 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/23 16:00:11 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <deque>

template <template <typename> class CT, typename T>
class PmergeMe
{
	public:
							PmergeMe(void);
							~PmergeMe(void);
		
		//const PmergeMe &	operator=(const PmergeMe & 

	private:
		CT<T>	_ct;

};

template <template <typename> class CT, typename T>
PmergeMe<CT, T>::PmergeMe(void)
{
	return;
}


template <template <typename> class CT, typename T>
PmergeMe<CT, T>::~PmergeMe(void)
{
	return;
}

int	main(void)
{
	PmergeMe<std::vector, int>	test __attribute__((unused));
	return (0);
}
