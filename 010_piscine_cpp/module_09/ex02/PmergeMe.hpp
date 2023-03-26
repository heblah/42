/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:18:51 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/25 09:32:23 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe
{
	public:
							PmergeMe(void);
							PmergeMe(const PmergeMe & pmerge);
							~PmergeMe(void);
		
		const PmergeMe &	operator=(const PmergeMe & pmerge);

		void				sort(char **argv);

	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;

		void				_mergeVector(int l, int m, int r);
		void				_mergeDeque(int l, int m, int r);
		void				_sortVector(int l, int r);
		void				_sortDeque(int l, int r);

};

#endif /* PMERGEME_HPP */
