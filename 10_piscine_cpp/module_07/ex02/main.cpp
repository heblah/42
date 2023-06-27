/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:11:16 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/09 16:48:24 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Array.hpp"

int	main(void)
{
	Array<int>		array __attribute__((unused)) (5);
	Array<int>		array2 __attribute__((unused)) (10);
	Array<int>		array3 __attribute__((unused));
	unsigned int	size = array.getSize();
	unsigned int	i = 0;

	std::cout << "========== Printing first array ===========" << std::endl;
	while (i < size)
	{
		array[i] = i + 1;
		std::cout << array[i] << std::endl;
		i++;
	}
	std::cout << "========== Printing second array ==========" << std::endl;
	std::cout << "========== before operator =" << std::endl;
	i = 0;
	while (i < array2.getSize())
		std::cout << array2[i++] << std::endl;
	std::cout << "========== after operator= until index == size" << std::endl;
	array2 = array;
	i = 0;
	while (i <= array2.getSize())
	{
		try {
			std::cout << array2[i] << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		i++;
	}
	std::cout << "========== Printing third array ===========" << std::endl;
	try {
		std::cout << array3[0] << std::endl;}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;}
	try {
		std::cout << array3[147] << std::endl;}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;}

	return (0);
}
