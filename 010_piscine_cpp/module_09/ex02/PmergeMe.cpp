/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 08:56:41 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/24 20:52:07 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

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
			this->_deque = NULL;
			try {
				this->_vector = new std::vector<int>;
				this->_vector = pmerge._vector;
			} catch (std::exception & e) {
				std::cerr << e.what() << std::endl;
				this->_vector = NULL;
				this->_flag = EMPTY;
			}
			break;

		case DEQUE:
			this->_vector = NULL;
			try {
				this->_deque = new std::deque<int>;
				this->_deque = pmerge._deque;
			} catch (std::exception & e) {
				std::cerr << e.what() << std::endl;
				this->_deque = NULL;
				this->_flag = EMPTY;
			}
			break;
	}
	return;
}

PmergeMe::PmergeMe(const t_flags flag)
{
	this->_flag = flag;
	switch ( this->_flag )
	{
		case VECTOR:
			this->_deque = NULL;
			this->_vector = new std::vector<int>;
			break;

		case DEQUE:
			this->_vector = NULL;
			this->_deque = new std::deque<int>;
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
const PmergeMe &	PmergeMe::operator=(const PmergeMe & pmerge)
{
	this->_flag = pmerge._flag;
	switch ( this->_flag )
	{
		case VECTOR :
			delete this->_vector;
			this->_vector = NULL;
			break;

		case DEQUE :
			delete this->_deque;
			this->_deque = NULL;
			break;
	}

	switch ( this->_flag )
	{
		case VECTOR:
			this->_deque = NULL;
			try {
				this->_vector = new std::vector<int>;
				this->_vector = pmerge._vector;
			} catch (std::exception & e) {
				std::cerr << e.what() << std::endl;
				this->_vector = NULL;
				this->_flag = EMPTY;
			}
			break;

		case DEQUE:
			this->_vector = NULL;
			try {
				this->_deque = new std::deque<int>;
				this->_deque = pmerge._deque;
			} catch (std::exception & e) {
				std::cerr << e.what() << std::endl;
				this->_deque = NULL;
				this->_flag = EMPTY;
			}
			break;
	}
	return ( *this );
}

// Member functions ========================================================= //
const t_flags &	PmergeMe::getFlag(void) const
{
	return ( this->_flag );
}

void	PmergeMe::sort(char **argv)
{
	const char	*c = NULL;
	//time_t		time[2];
	time_t		start;
	time_t		end;

	while (argv && *argv)
	{
		c = *argv;
		while (*c)
		{
			if ( (*c < '0' || *c > '9') && *c != '+')
			{
				std::cerr << "Error." << std::endl;
				return;
			}
			c++;
		}
		if ( this->_flag == VECTOR )
			this->_vector->push_back( atoi(*argv) );
		else if ( this->_flag == DEQUE )
			this->_deque->push_back( atoi(*argv) );
		argv++;
	}

	start = std::time( nullptr );
	if ( this->_flag == VECTOR )
		this->_mergeSort( 0, this->_vector->size() - 1 );
	else if ( this->_flag == DEQUE )
		this->_mergeSort( 0, this->_deque->size() - 1 );
	end = std::time( nullptr );

//	std::cout << "difftime = " << std::difftime( time[2], time[1] ) << std::endl;
	std::cout << "difftime = " << std::difftime( end, start ) << std::endl;
	return;
}

void	PmergeMe::_mergeDeque(int l, int m, int r)
{
	if ( this->_flag != EMPTY )
	{
		int i, j, k;
		int n1 = m - l + 1;
		int n2 = r - m;

		std::deque<int> L(n1);
		std::deque<int> R(n2);
		std::deque<int> &arr = *( this->_deque );

		for (i = 0; i < n1; i++)
			L[i] = arr[l + i];
		for (j = 0; j < n2; j++)
			R[j] = arr[m + 1 + j];

		i = 0;
		j = 0;
		k = l;
		while (i < n1 && j < n2) {
			if (L[i] <= R[j]) {
				arr[k] = L[i];
				i++;
			}
			else {
				arr[k] = R[j];
				j++;
			}
			k++;
		}

		while (i < n1) {
			arr[k] = L[i];
			i++;
			k++;
		}

		while (j < n2) {
			arr[k] = R[j];
			j++;
			k++;
		}
	}
	return;
}

void	PmergeMe::_mergeVector(int l, int m, int r)
{
	if ( this->_flag != EMPTY )
	{
		int i, j, k;
		int n1 = m - l + 1;
		int n2 = r - m;

		std::vector<int> L(n1);
		std::vector<int> R(n2);
		std::vector<int> &arr = *( this->_vector );

		for (i = 0; i < n1; i++)
			L[i] = arr[l + i];
		for (j = 0; j < n2; j++)
			R[j] = arr[m + 1 + j];

		i = 0;
		j = 0;
		k = l;
		while (i < n1 && j < n2) {
			if (L[i] <= R[j]) {
				arr[k] = L[i];
				i++;
			}
			else {
				arr[k] = R[j];
				j++;
			}
			k++;
		}

		while (i < n1) {
			arr[k] = L[i];
			i++;
			k++;
		}

		while (j < n2) {
			arr[k] = R[j];
			j++;
			k++;
		}
	}
	return;
}

void	PmergeMe::_mergeSort(int l, int r)
{
	if ( this->_flag != EMPTY )
	{
		int m = l + (r - l) / 2;

		if (l >= r) {
			return;
		}

		this->_mergeSort(l, m);
		this->_mergeSort(m + 1, r);
		if ( this->_flag == VECTOR )
			this->_mergeVector(l, m, r);
		else if ( this->_flag == DEQUE )
			this->_mergeDeque(l, m, r);
	}
	return;
}

// Exceptions =============================================================== //

