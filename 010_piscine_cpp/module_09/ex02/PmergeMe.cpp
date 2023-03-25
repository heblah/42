/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 08:56:41 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/25 16:59:57 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "PmergeMe.hpp"

// Constructors ============================================================= //
PmergeMe::PmergeMe(void)
{
	return;
}

PmergeMe::PmergeMe(const PmergeMe & pmerge)
{
	this->_vector = pmerge._vector;
	this->_deque = pmerge._deque;
	return;
}

// Destructor =============================================================== //
PmergeMe::~PmergeMe(void)
{
	return;
}

// Operators ================================================================ //
const PmergeMe &	PmergeMe::operator=(const PmergeMe & pmerge)
{
	if ( this->_vector.size() > 0 )
		this->_vector.clear();
	if ( this->_deque.size() > 0 )
		this->_deque.clear();
	this->_vector = pmerge._vector;
	this->_deque = pmerge._deque;
	return ( *this );
}

// Member functions ========================================================= //
void	PmergeMe::sort(char **argv)
{
	const char	*c = NULL;
	time_t		start;
	time_t		end;
	long		time[2] __attribute__((unused));
	size_t		i = 0;

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
		this->_vector.push_back( atoi(*argv) );
		this->_deque.push_back( atoi(*argv) );
		argv++;
	}

	std::cout << "Before : ";
	i = 0;
	while ( i < 6 && i < this->_vector.size() )
	{
		std::cout << this->_vector[i++] << " ";
	}
	std::cout << "..." << std::endl;

	start = std::time( nullptr );
	this->_sortVector( 0, this->_vector.size() - 1 );
	end = std::time( nullptr );
	time[1] = std::difftime( end, start );

	start = std::time( nullptr );
	this->_sortDeque( 0, this->_deque.size() - 1 );
	end = std::time( nullptr );
	time[2] = std::difftime( end, start );

	std::cout << "After : ";
	i = 0;
	while ( i < 6 && i < this->_vector.size() )
	{
		std::cout << this->_vector[i++] << " ";
	}
	std::cout << ( ( this->_vector.size() > i ) ? "..." : "" )  << std::endl;

	//std::cout << "difftime = " << std::difftime( time[2], time[1] ) << std::endl;
	std::cout << "difftime = " << std::difftime( end, start ) << std::endl;
	return;
}

void	PmergeMe::_mergeDeque(int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	std::deque<int> L(n1);
	std::deque<int> R(n2);
	std::deque<int> &arr = this->_deque;

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
	return;
}

void	PmergeMe::_mergeVector(int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	std::vector<int> L(n1);
	std::vector<int> R(n2);
	std::vector<int> &arr = this->_vector;

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
	return;
}

void	PmergeMe::_sortVector(int l, int r)
{
	int m = l + (r - l) / 2;

	if (l >= r) {
		return;
	}

	this->_sortVector(l, m);
	this->_sortVector(m + 1, r);

	this->_mergeVector(l, m, r);
	return;
}

void	PmergeMe::_sortDeque(int l, int r)
{
	int m = l + (r - l) / 2;

	if (l >= r) {
		return;
	}

	this->_sortDeque(l, m);
	this->_sortDeque(m + 1, r);

	this->_mergeDeque(l, m, r);
	return;
}
// Exceptions =============================================================== //

