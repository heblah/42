/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:11:13 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/24 12:21:07 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Constructors ============================================================= */
Dog::Dog(void)
{
	std::cout << "Default Dog constructor called" << std::enl;
	return;
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	std::cout << "Copy Dog constructor called" << std::enl;
	//this->setType(dog.getType());
	return;
}

/* Destructor =============================================================== */
Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	return;
}

/* Operators ================================================================ */
Dog & Dog::operator=(const Dog &dog)
{
	this->setType(dog.getType());
	return (*this);
}

/* Member functions ========================================================= */
void	Dog::makeSound(void) const
{
	std::cout << "Dog's sound : Wouaf wouaf wouaf" << std::endl;
	return;
}
