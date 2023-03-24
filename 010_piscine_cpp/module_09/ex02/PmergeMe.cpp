/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 08:56:41 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/24 10:56:07 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "PmergeMe.hpp"

// Constructors ============================================================= //
PmergeMe::PmergeMe(void)
{
	this->_flag = VECTOR;
	try {
		this->_vector = new std::vector<int>;
		this->_deque = NULL;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		this->_vector = NULL;
		this->_flag = EMPTY;
	}
	return;
}

PmergeMe::PmergeMe(const PmergeMe & pmerge)
{
	this->_flag = pmerge._flag;
	switch ( this->_flag )
	{
		case VECTOR:
			this->_vector = new std::vector<int>;
			this->_vector = pmerge._vector;
			this->_deque = NULL;
			break;
		case DEQUE:
			this->_deque = new std::deque<int>;
			this->_deque = pmerge._deque;
			this->_vector = NULL;
			break;
	}
	return;
}

// Destructor =============================================================== //
PmergeMe::~PmergeMe(void)
{
	switch ( this->_flag )
	{
		case VECTOR:
			delete this->_vector;
			break;
		case DEQUE:
			delete this->_deque;
			break;
	}
	return;
}

// Operators ================================================================ //

// Member functions ========================================================= //

// Exceptions =============================================================== //

