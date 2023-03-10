/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:04:50 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/10 17:09:22 by halvarez         ###   ########.fr       */
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
	MutantStack< int >	cpytack __attribute__((unused)) (deftack);
	std::stack<int>	stack;

	deftack.top();

	//deftack.getStack().swap( cpytack.getStack() );
	//std::cout << deftack.pop() <<std::endl;
	//std::cout << deftack.pop() <<std::endl;
	return (0);
}
