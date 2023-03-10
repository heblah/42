/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:08:07 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/10 11:48:42 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP 

#define PRINT 1

// Template : generic ======================================================= //
template <typename Base>
class MutantStack : public Base
{
	public:
		typedef typename Base::const_reference ConstBaseRef;

									MutantStack(void);
									MutantStack(const MutantStack & mp);
									~MutantStack(void);

		const MutantStack<Base> &	operator=(const MutantStack & ms);

		ConstBaseRef				getContainer(void) const;

	private:
		Base			_container;

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
