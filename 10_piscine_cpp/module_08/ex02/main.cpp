/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:04:50 by halvarez          #+#    #+#             */
/*   Updated: 2023/04/24 11:42:00 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <assert.h>

#include "MutantStack.hpp"

int	tests42(void)
{
	std::cout << "========== Testing from subject ===========" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

int	main(void)
{
	MutantStack< int >	deftack __attribute__((unused));
	MutantStack< int >	equtack __attribute__((unused));

	deftack.push( 1 );
	deftack.push( 2 );
	deftack.push( 3 );
	MutantStack< int >	cpytack __attribute__((unused)) (deftack);
	equtack = deftack;

	std::cout << std::endl;
	std::cout << "========== Testing default stack ==========" << std::endl;
	std::cout << deftack.top() << std::endl;

	std::cout << std::endl;
	std::cout << "========== Testing copy stack =============" << std::endl;
	std::cout << cpytack.top() << std::endl;

	std::cout << std::endl;
	std::cout << "========== Testing equal stack ============" << std::endl;
	std::cout << equtack.top() << std::endl;

	std::cout << std::endl;
	std::cout << "========== Testing begin iterator =========" << std::endl;
	MutantStack<int>::iterator 	it __attribute__((unused)) = deftack.begin();
	std::cout << *it <<std::endl;
	it++;
	std::cout << *it <<std::endl;
	it++;
	std::cout << *it <<std::endl;
	it++;
	std::cout << *it <<std::endl;
	it++;
	std::cout << *it <<std::endl;

	std::cout << std::endl;
	std::cout << "========== Testing end iterator ===========" << std::endl;
	it = deftack.end();
	std::cout << *(--it) <<std::endl;
	it--;
	std::cout << *it <<std::endl;
	it--;
	std::cout << *it <<std::endl;

	std::cout << std::endl;
	std::cout << "========== Testing rbegin r_iterator ======" << std::endl;
	MutantStack<int>::r_iterator 	rit __attribute__((unused)) = deftack.rbegin();
	rit = deftack.rbegin();
	std::cout << *rit <<std::endl;
	rit++;
	std::cout << *rit <<std::endl;
	rit++;
	std::cout << *rit <<std::endl;

	std::cout << std::endl;
	std::cout << "========== Testing rend r_iterator ========" << std::endl;
	rit = deftack.rend();
	std::cout << *(--rit) <<std::endl;
	rit--;
	std::cout << *rit <<std::endl;
	rit--;
	std::cout << *rit <<std::endl;

	std::cout << std::endl;
	tests42();

	std::cout << std::endl;
	return (0);
}
