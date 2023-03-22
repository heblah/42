/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:26:11 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/22 10:21:34 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "RPN.hpp"

/* Constructors ============================================================= */
RPN::RPN(void)
{
	this->_badChar = false;
	return;
}

RPN::RPN(const RPN & rpn)
{
	while (this->_stack.size() > 0)
		this->_stack.pop();
	this->_stack = rpn.getStack();
	this->_badChar = rpn.getFlag();
	return;
}

/* Destructor =============================================================== */
RPN::~RPN(void)
{
	return;
}

/* Operators ================================================================ */
const RPN &	RPN::operator=(const RPN &rpn)
{
	return (*this);
}

/* Member functions ========================================================= */
const std::stack<char> &	RPN::getStack(void) const
{
	return ( this->_stack );
}

const bool &	RPN::getFlag(void) const
{
	return (this->_badChar);
}

void	RPN::push(const char & c)
{
	
	this->_stack.push(c);
	return;
}

void	RPN::pop(void)
{
	this->_stack.pop();
	return;
}

const char &	RPN::top(void)
{
	return ( this->_stack.top() );
}


const int	op(void);
