/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:18:51 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/24 10:54:41 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

typedef enum e_flags
{
	EMPTY	= 0,
	VECTOR	= 0 << 1,
	DEQUE	= 1 << 1,
}	t_flags;

class PmergeMe
{
	public:
							PmergeMe(void);
							PmergeMe(const PmergeMe & pmerge);
							PmergeMe(const t_flags flag);
							~PmergeMe(void);
		
		const PmergeMe &	operator=(const PmergeMe & pmerge);



	private:
		std::vector<int>	*_vector;
		std::deque<int>		*_deque;
		t_flags				_flag;

};

#endif /* PMERGEME_HPP */
