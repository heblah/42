/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:31:16 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/24 15:36:29 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Cat.hpp"
#include "Dog.hpp"

void	tests_animal(void)
{
/* Animal tests ============================================================= */
	std::cout << "==================== Testing Animal ====================" << std::endl;
	Animal	*panimal = new Animal();
	Animal	animal("bidul");;

	std::cout << std::endl << "Pointer/ Animal :" << std::endl;
	std::cout << "Sound of panimal : ";
	panimal->makeSound();
	std::cout << "Type of panimal : " << panimal->getType() << std::endl;
	std::cout << std::endl << "Animal :" << std::endl;
	std::cout << "Type of animal : " << animal.getType() << std::endl;
	std::cout << "Sound of animal : ";
	animal.makeSound();

	std::cout << std::endl;
	delete panimal;
	return;
}

void	tests_cat(void)
{
	std::cout << "==================== Testing Cat =======================" << std::endl;
	Animal	*pAcat = new Cat("Idefix by alloc");
	Cat		cat("Idefix by stack");
	Cat		*pcat;


	std::cout << std::endl << "Using pointer on animal : " << std::endl;
	std::cout << pAcat->getType() << " ";
	pAcat->makeSound();
	std::cout << pAcat->getType() << " ";
	pAcat->Animal::makeSound();

	std::cout << std::endl << "Using pointer on cat : " << std::endl;
	pcat = &cat;
	std::cout << pcat->getType() << " ";
	pcat->makeSound();
	std::cout << pcat->getType() << " ";
	pcat->Animal::makeSound();
	std::cout << std::endl;

	delete pAcat;
	return;
}

void	tests_dog(void)
{
	std::cout << "==================== Testing Dog =======================" << std::endl;
	Animal	*pAdog = new Dog("Idefix by alloc");
	Dog		dog("Idefix by stack");
	Dog		*pdog;


	std::cout << std::endl << "Using pointer on animal : " << std::endl;
	std::cout << pAdog->getType() << " ";
	pAdog->makeSound();
	std::cout << pAdog->getType() << " ";
	pAdog->Animal::makeSound();

	std::cout << std::endl << "Using pointer on dog : " << std::endl;
	pdog = &dog;
	std::cout << pdog->getType() << " ";
	pdog->makeSound();
	std::cout << pdog->getType() << " ";
	pdog->Animal::makeSound();
	std::cout << std::endl;

	delete pAdog;
	return;
}

int	main(void)
{
	tests_animal();
	std::cout << std::endl;

	tests_cat();
	std::cout << std::endl;
	
	tests_dog();
	std::cout << std::endl;
	return (0);
}
