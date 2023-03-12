/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:31:16 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/12 16:33:25 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#define SIZE 100

void	tests_animal(void)
{
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
	Animal	*pAcat = new Cat("Miaouss by alloc");
	Cat		cat("Miaouss by stack");
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
	std::cout << pcat->getType() << " using pcat->Animal::makeSound() ";
	pcat->Animal::makeSound();
	std::cout << std::endl;

	std::cout << "Casting Cat* into Dog* using memory allocated on Animal* with :";
	std::cout << std::endl;
	std::cout << "Animal *pAcat = new Cat(\"Miaouss by alloc\"); " <<std::endl;
	Dog	*pdog = (Dog *)pcat;
	std::cout << "pdog->makeSound(); :" <<std::endl;
	pdog->makeSound();
	std::cout << "pdog->Cat::makeSound(); Sends a compilation error:" << std::endl;
	std::cout << "error: ‘Cat’ is not a base of ‘Dog’" << std::endl;
	std::cout << "pdog->Dog::makeSound(); :" <<std::endl;
	pdog->Dog::makeSound();
	std::cout << "pdog->Animal::makeSound(); :" <<std::endl;
	pdog->Animal::makeSound();

	std::cout << std::endl << "pcat = (Cat *)pAcat;\ndelete pcat;" << std::endl;
	pcat = (Cat *)pAcat;
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
	std::cout << pdog->getType() << " using pdog->Animal::makeSound() ";
	pdog->Animal::makeSound();
	std::cout << std::endl;

	delete pAdog;
	return;
}

void	tests_wrong(void)
{
	std::cout << "==================== Testing Wrong Animal and WrongCat =" << std::endl;
	WrongAnimal wa("Tortue Géniale");
	WrongCat	wcat("Felix le chat");

	std::cout << "Tortue Géniale :";
	wa.makeSound();
	std::cout << "Vieux chat:";
	wcat.makeSound();
	std::cout << std::endl;
	return;
}

void	tests_brain_array(void)
{
	std::cout << "==================== Testing brain animals ==============" << std::endl;
	Animal			*panimal[SIZE];
	unsigned int	n = SIZE;

	while (--n > 0)
	{
		if (n >= SIZE / 2)
		{
			panimal[n] = new Dog;
			panimal[n]->makeSound();
		}
		else
		{
			panimal[n] = new Cat;
			panimal[n]->makeSound();
		}
	}

	n = SIZE;
	while (--n > 0)
		delete *(panimal + n);
	return;
}

void	tests_brain_idea(void)
{
	std::cout << "==================== Testing brain ideas ================" << std::endl;
	Cat 		cat("Felix");
	std::string	idea = "Idea n.";
	std::cout << std::endl;

	cat.setIdea("Whiskas", 1);
	std::cout << cat.getType() << " wants some " << cat.getIdea(1) <<std::endl;
	for (int i = 1; i <= SIZE; i++)
	{
		idea += i;
		cat.setIdea(idea, i);
		idea = "Idea n.";
	}
	for (int i = 0; i <= SIZE; i++)
		std::cout << i << "-" << cat.getIdea(i) << std::endl;

	std::cout <<std::endl;
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

	tests_wrong();
	std::cout << std::endl;

	tests_brain_array();
	std::cout << std::endl;

	tests_brain_idea();
	std::cout << std::endl;
	return (0);
}
