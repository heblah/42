/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:18:51 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/23 16:08:17 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

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

#include "PmergeMe.tpp"

#endif /* PMERGEME_HPP */
