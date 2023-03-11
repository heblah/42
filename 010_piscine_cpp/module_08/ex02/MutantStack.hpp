/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:08:07 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/11 17:58:14 by halvarez         ###   ########.fr       */
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
		typedef typename std::stack<T>::const_reference ConstStackRef;
		typedef typename std::stack<T>::container_type::iterator iterator;

								MutantStack(void);
								MutantStack(const MutantStack & mp);
								~MutantStack(void);

		const MutantStack<T> &	operator=(const MutantStack & ms);

		ConstStackRef			getStack(void) const;
		void					push(const T & elem);
		void					pop(void);
		T &						top(void);

		iterator				begin(void) const;

	private:
		std::stack<T>			_stack;

};

#include "MutantStackGeneric.tpp"

/*
// Template : std::stack ==================================================== //
template <typename T>
class MutantStack <std::stack, T > : public std::stack<T>
{
	public:
							MutantStack(void);
							MutantStack(const MutantStack & mp);
							~MutantStack(void);

		const MutantStack &	operator=(const MutantStack & ms);

		class Iterator
		{
								Iterator(void);
								Iterator(const Iterator & it);
								~Iterator(void);

			const Iterator &	operator=(void);

			const Iterator &	operator++(void);
			const Iterator &	operator++(int);
			const Iterator &	operator--(void);
			const Iterator &	operator--(int);
		};

	private:
		std::stack<T>			_container;

};

#include "MutantStackceStdStack.tpp"
*/

#endif /* MUTANTSTACK_HPP */
