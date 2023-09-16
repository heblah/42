/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:26:11 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/31 12:22:20 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stack>

#include "RPN.hpp"

/* Constructors ============================================================= */
RPN::RPN(void)
{
	return;
}

RPN::RPN(const RPN & rpn)
{
	while ( this->_stack.size() > 0 )
		this->_stack.pop();
	this->_stack = rpn.getStack();
	return;
}

/* Destructor =============================================================== */
RPN::~RPN(void)
{
	return;
}

/* Operators ================================================================ */
RPN &	RPN::operator=(const RPN &rpn)
{
	while ( this->_stack.size() > 0 )
		this->_stack.pop();
	this->_stack = rpn.getStack();
	return (*this);
}

/* Member functions ========================================================= */
int	RPN::op(const char * str)
{
	int	res = 0;
	int	tmp = 0;

	while (str && *str)
	{
		res = 0;
		tmp = 0;
		if ( (*str < '0' || *str > '9')
			&& *str != '+'
			&& *str != '-'
			&& *str != '*'
			&& *str != '/'
			&& *str != ' ' )
			throw WrongSyntax();
		switch ( *str )
		{
			case '+':
				tmp += this->_stack.top();
				this->_stack.pop();
				if ( this->_stack.size() == 0 )
					throw WrongSyntax();
				res = this->_stack.top() + tmp;
				this->_stack.pop();
				this->_stack.push( res );
				break;
			case '-':
				tmp += this->_stack.top();
				this->_stack.pop();
				if ( this->_stack.size() == 0 )
					throw WrongSyntax();
				res = this->_stack.top() - tmp;
				this->_stack.pop();
				this->_stack.push( res );
				break;
			case '*':
				tmp += this->_stack.top();
				this->_stack.pop();
				if ( this->_stack.size() == 0 )
					throw WrongSyntax();
				res = this->_stack.top() * tmp;
				this->_stack.pop();
				this->_stack.push( res );
				break;
			case '/':
				tmp += this->_stack.top();
				if (tmp == 0)
					throw ZeroDivision();
				this->_stack.pop();
				if ( this->_stack.size() == 0 )
					throw WrongSyntax();
				res = this->_stack.top() / tmp;
				this->_stack.pop();
				this->_stack.push( res );
				break;
			default:
				if (*str != ' ')
					this->_stack.push( *str - '0' );
		}
		str++;
	}
	str--;
	if (*str != '+'
		&& *str != '-'
		&& *str != '*'
		&& *str != '/'
		&& *str != ' ' )
		throw WrongSyntax();
	res = this->_stack.top();
	this->_stack.pop();
	return ( res );
}

const std::stack<int> &	RPN::getStack(void) const
{
	return ( this->_stack );
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
