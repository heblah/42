/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:08:07 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/12 14:28:41 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP 

#define PRINT 1

// Template : generic ======================================================= //
template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator			iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator	r_iterator;

							MutantStack(void);
							MutantStack(const MutantStack & mp);
							~MutantStack(void);

		MutantStack<T> &	operator=(const MutantStack & ms);

		iterator			begin(void);
		iterator			end(void);
		r_iterator			rbegin(void);
		r_iterator			rend(void);

};

#include "MutantStackGeneric.tpp"

#endif /* MUTANTSTACK_HPP */
