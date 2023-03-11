/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:04:50 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/11 16:22:37 by halvarez         ###   ########.fr       */
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
	std::cout << "========== Testing equalstack =============" << std::endl;
	std::cout << equtack.top() << std::endl;
	return (0);
}
